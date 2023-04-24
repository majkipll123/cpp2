#include "image.h"

#include <fstream>
#include <filesystem>
#include <iostream>
#include <stdexcept>
#include <cmath>

void Image::load(const std::string& filename)
{
    constexpr auto MAGIC = "P6";

    this->filename = filename;

    std::ifstream in(filename, std::ios::binary);
    if (!in) throw std::invalid_argument("failed to open \"" + filename + "\"");

    in >> magic;
    if (magic != MAGIC) throw std::logic_error("unknown magic naumber " + magic);

    in >> my_width >> my_height >> color_depth;

    if (!in || my_width < 0 || my_width > 10000 || my_height < 0 || my_height > 10000 || color_depth <= 0 ||
        color_depth > 255)
        throw std::logic_error("invalid image parameter(s): " + std::to_string(my_width) + " " +
                               std::to_string(my_height) + " " + std::to_string(color_depth));
    in.ignore(1);
    pixels.resize(my_height);
    for (auto& line : pixels)
    {
        line.resize(my_width);
        in.read(reinterpret_cast<char*>(&line[0]), my_width * sizeof(RGB));
        if (!in) throw std::logic_error("failed to read binary pixel data from file " + filename);
    }
}

void Image::save_as(const std::string& filename) {
//zapisuje obrazek do pliku
    std::ofstream out(filename, std::ios::binary);

    if (!out) throw std::invalid_argument("failed to open \"" + filename + "\"");
///zapisuje naglowek
    out << "P6\n" << my_width << " " << my_height << "\n" << color_depth << "\n";
///zapisuje pixeli
    for (const auto& line : pixels)
    {
        out.write(reinterpret_cast<const char*>(&line[0]), my_width * sizeof(RGB));
    }

    out.close();
}
//tworzenie fioletowego krzyza w lewym gornym rogu obrazka
void Image::add_watermark() {
    RGB violet = {255, 0, 255};
        
        int w=500;
        for (int h = 2; h <= my_height-10; h++) 
        {
        pixels[(my_height / 4) - h/4][(my_width / 4) - w/4] = violet;
        pixels[(my_height / 4) - 1][(my_width / 4) + 1] = violet;
        pixels[(my_height / 4) + h/4][(my_width / 4) - w/4] = violet;
        pixels[(my_height / 4) + 1][(my_width / 4) + 1] = violet; //podmianka pixeli na fioletowy
        if(w>=2)
        w--;
        else
        w=500;
        }
        
    }

void Image::blurr()
{

    std::vector<std::vector<RGB>> temp_pixels = pixels;

    //przechodzimy po wszystkich pixelach obrazka
    for (int w = 1; w <= my_width-2; w++) {
        
        for (int h = 1; h <= my_height-2; h++) 
        {
           
            //obliczamy srednia wartosc pixeli wokol
            temp_pixels[h][w].red = (pixels[h][w].red + pixels[h][w + 1].red + pixels[h][w - 1].red + pixels[h + 1][w].red + pixels[h + 1][w + 1].red + pixels[h + 1][w - 1].red + pixels[h - 1][w].red + pixels[h - 1][w + 1].red + pixels[h - 1][w - 1].red) / 9;
            temp_pixels[h][w].green = (pixels[h][w].green + pixels[h][w + 1].green + pixels[h][w - 1].green + pixels[h + 1][w].green + pixels[h + 1][w + 1].green + pixels[h + 1][w - 1].green + pixels[h - 1][w].green + pixels[h - 1][w + 1].green + pixels[h - 1][w - 1].green) / 9;
            temp_pixels[h][w].blue = (pixels[h][w].blue + pixels[h][w + 1].blue + pixels[h][w - 1].blue + pixels[h + 1][w].blue + pixels[h + 1][w + 1].blue + pixels[h + 1][w - 1].blue + pixels[h - 1][w].blue + pixels[h - 1][w + 1].blue + pixels[h - 1][w - 1].blue) / 9;
        }
    }
    pixels = temp_pixels;
    
}
//tworzenie obrazka z jednej warstwy koloru
void Image::extract_layer(ColorLayer color_layer) {
 //przechodzimy po wszystkich pixelach obrazka
    for (int w = 0; w <= my_width; w++) {
        for (int h = 0; h < my_height; h++) {
            if (color_layer == ColorLayer::Red) {
                //zerujemy niepotrzebne warstwy
                pixels[h][w].green = 0;
                pixels[h][w].blue = 0;
            }
            if (color_layer == ColorLayer::Green) {
                //zerujemy niepotrzebne warstwy
                pixels[h][w].red = 0;
                pixels[h][w].blue = 0;
            }
            if (color_layer == ColorLayer::Blue) {
                //zerujemy niepotrzebne warstwy
                pixels[h][w].red = 0;
                pixels[h][w].green = 0;
            }
        }//koniec petli for
    }
}

void Image::filter() {
//przechodzimy po wszystkich pixelach obrazka
    for (int w = 0; w <= (my_width - 1); w++) {
        for (int h = 0; h < (my_height - 1); h++) {
            //obliczamy wartosc absolutna roznicy miedzy pixelami
            pixels[h][w].red = abs(pixels[h][w].red - pixels[h+1][w+1].red);
            pixels[h][w].green = abs(pixels[h][w].green - pixels[h+1][w+1].green);
            pixels[h][w].blue = abs(pixels[h][w].blue - pixels[h+1][w+1].blue);
            //obliczona wartosc daje nam filtr krawedzi
        }
    }
}

void Image::flip_horizontally() {

    std::vector<std::vector<RGB>> temp_pixels = pixels;
    
    for (int w = 0; w <= my_width-2; w++) {
        for (int h = 0; h < my_height-2; h++) {
            temp_pixels[h][w] = pixels[h][my_width - w];
        }
    }

    pixels = temp_pixels;
}

void Image::flip_vertically() {
    //przechodzimy po wszystkich pixelach obrazka
    std::vector<std::vector<RGB>> temp_pixels = pixels;
    //
    for (int w = 0; w <= my_width-1; w++) {
        
        for (int h = 0; h < my_height-1; h++) {
            //zamienia pixel na pixel o przeciwnym indeksie
            temp_pixels[h][w] = pixels[my_height - h - 1][w];
        }
    }

    pixels = temp_pixels;
}

void Image::inflate() {

    std::vector<std::vector<RGB>> temp_pixels = pixels;
    int x = 0;
    int y = 0;

    for (int w = 0; w <= my_width - 1; w += 2) {
        for (int h = 0; h < my_height - 1; h += 2) {
            temp_pixels[h][w] = pixels[y][x];
            temp_pixels[h][w + 1] = pixels[y][x];
            temp_pixels[h + 1][w] = pixels[y][x];
            temp_pixels[h + 1][w + 1] = pixels[y][x];
            y++;
        }

        y = 0;
        x++;
    }

    pixels = temp_pixels;
}

void Image::negative() {
// obraca atkualne pixele na przeciwne 255 - aktualny pixel
    for (int w = 0; w < my_width; w++) {
        for (int h = 0; h < my_height; h++) {
            pixels[h][w].red = 255 - pixels[h][w].red;
            pixels[h][w].green = 255 - pixels[h][w].green;
            pixels[h][w].blue = 255 - pixels[h][w].blue;
        }
    }
}

void Image::rotate_clockwise_90() {

    // moim zdaniem w tej funkcji przydałby się argument filename, aby odczytać nagłówek
    // pliku ppm i móc go zmienić, ponieważ obracając musimy zamienić szer. i wys. miejscami

    std::vector<std::vector<RGB>> temp_pixels = pixels;
    int red, green, blue;

    for (int w = 0; w <= my_width-1; w++) {
        for (int h = 0; h <= my_height-1; h++) {
            red = pixels[h][w].red;
            green = pixels[h][w].green;
            blue = pixels[h][w].blue;
            temp_pixels[w][my_height - h/2 - 1].red = red;
            temp_pixels[w][my_height - h/2 - 1].green = green;
            temp_pixels[w][my_height - h/2 - 1].blue = blue;
        }
    }
}

void Image::sepia() {
    
    std::vector<std::vector<RGB>> temp_pixels = pixels;
    int nr, ng, nb;

    for (int w = 0; w < my_width; w++) {
        for (int h = 0; h < my_height; h++) {
            //obliczamy nowe wartosci pixeli dla ktorych jest wartosc sepii
            nr = round(0.393*pixels[h][w].red + 0.769*pixels[h][w].green + 0.189*pixels[h][w].blue);
            ng = round(0.349*pixels[h][w].red + 0.686*pixels[h][w].green + 0.168*pixels[h][w].blue);
            nb = round(0.272*pixels[h][w].red + 0.534*pixels[h][w].green + 0.131*pixels[h][w].blue);
        
            pixels[h][w].red = (nr > 255) ? 255 : nr;
            pixels[h][w].green = (ng > 255) ? 255 : ng;
            pixels[h][w].blue = (nb > 255) ? 255 : nb;
        }
    }
}

void Image::shrink() {

    // ...
}

void Image::to_grayscale() {

    int grayscale = 0;

    for (int w = 0; w < my_width; w++) {
        //przechodzimy po wszystkich pixelach obrazka
        for (int h = 0; h < my_height; h++) {
            
            grayscale = ((pixels[h][w].red + pixels[h][w].green + pixels[h][w].blue) / 3);
            //ustawiamy wartosc pixela na wartosc szarosci
            pixels[h][w].red = grayscale;
            pixels[h][w].green = grayscale;
            pixels[h][w].blue = grayscale;
        }
    }
}

int main() {

    Image obrazek;

    obrazek.load("tree.ppm");
    //obrazek.add_watermark(); 
    //for (int i=0; i<100; i++)
    //obrazek.blurr(); //czale na czarno
    //obrazek.extract_layer(ColorLayer::Blue);//dziala
    //obrazek.filter(); //kontury - dziala
    //obrazek.flip_horizontally(); //dziala
    //obrazek.flip_vertically();//dziala
    //obrazek.inflate();//dziala
    //obrazek.negative(); // dziala
    //obrazek.rotate_clockwise_90();//niedziala
    //obrazek.sepia();//dziala
    //obrazek.shrink();
    //obrazek.to_grayscale();//dziala
    std::cout << obrazek.height();
    std::cout << obrazek.width();
    obrazek.save_as("test.ppm");

    return 0;
}