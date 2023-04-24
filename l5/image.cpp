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

void width(const std::string& filename)
{
    constexpr auto MAGIC = "P6";


    std::ifstream in(filename, std::ios::binary);
    if (!in) throw std::invalid_argument("failed to open \"" + filename + "\"");

    //std::cout<<"Width of the image is :" << my_width << std::endl;    
    
    }

void height()
    {
        int sum = 0;
        //zwraca wysokosc obrazka
        for (int i=0; i < sum; i++)
        {
            sum++;
            std::cout << "Height: " << sum << std::endl;
        }
    }

void Image::save_as(const std::string& filename)
{
    std::ofstream out(filename, std::ios::binary);
    if (!out) throw std::invalid_argument("failed to open \"" + filename + "\"");
    
    out << magic << " " << my_width << " " << my_height << " " << color_depth << " ";
    
    if ( !out ) throw std::logic_error("failed to write binary pixel data to file " + filename);
    for (auto& line : pixels)
    {
        out.write(reinterpret_cast<char*>(&line[0]), my_width * sizeof(RGB));
        if (!out) throw std::logic_error("failed to write binary pixel data to file " + filename);
    }
    
}

void Image::add_watermark() {

    RGB red_pixel = {255, 0, 0};
    int w = 0;

    for (int h = 0; h < (my_height / 2); h++) {        
        pixels[(my_height / 2) - h][(my_width / 2) - w] = red_pixel;
        pixels[(my_height / 2) - h][(my_width / 2) + w] = red_pixel;
        pixels[(my_height / 2) + h][(my_width / 2) - w] = red_pixel;
        pixels[(my_height / 2) + h][(my_width / 2) + w] = red_pixel;
        w++;
    }
}

void blurr()
    {
        //Rozmyj obrazek. Rozmycie polega na zastąpieniu wartości składowych kolorów piksela (x, y) wartościami 
        //średnimi arytmetycznymi, w każdym kanale kolorów liczoną osobno, z wartości koloru w ośmiu sąsiednich pikselach oryginału.
    }

void extract_layer(ColorLayer color_layer)
    //ten layer ma byc wyciagniety poprzez zerowanie 2 z 3 skladwoych kolorow 
    {
    
    }
void filter()
    {//Magiczny filtr” polega na zastąpieniu wartości składowych kolorów piksela (x, y) wartościami
     //bezwzględnymi różnic tych składowych w pozycji (x, y) i (x+1, y+1). Uważaj na brzegi.
        
    }
void flip_horizontally()
    {
        //Odwróć obrazek w poziomie
    }
void flip_vertically()
    {
        //Odwróć obrazek w pionie
    }
void inflate()
    {
        //Powiększ obrazek dwukrotnie
    }
void negative()
    {
        //Zamień obrazek na negatyw
    }


void rotate_clockwise_90()
    {
        //Obróć obrazek o 90 stopni w prawo

        
    }
void sepia()
    {
        //Zamień obrazek na sepie
    }
void shrink()
    {
        //Zmniejsz obrazek dwukrotnie do pixela x,y wpisujemy średnią arytmetyczną, w każdym kanale kolorów liczoną osobno, z wartości koloru w czterech
        //sąsiednich pikselach oryginału. Jak obliczyć ich współrzędne? 
    }
void to_grayscale()
    {
        //Zamień obrazek na skale szarości
    }

int main() {

    Image obrazek;

    obrazek.load("obrazek.ppm");
    obrazek.add_watermark();
    // nie dziala obrazek.blurr();
    // dziala obrazek.extract_layer(ColorLayer::Red);
    // obrazek.filter();
    // obrazek.flip_horizontally();
    // nie dziala obrazek.flip_vertically();
    // obrazek.inflate();
    // same obrazek.negative();
    // obrazek.rotate_clockwise_90();
    // obrazek.sepia();
    // obrazek.shrink();
    // dziala obrazek.to_grayscale();
    // nie dziala std::cout << obrazek.height();
    // nie dziala std::cout << obrazek.width();
    obrazek.save_as("test.ppm");

    return 0;
}