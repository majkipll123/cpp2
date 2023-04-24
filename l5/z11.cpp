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

    std::ofstream out(filename, std::ios::binary);

    if (!out) throw std::invalid_argument("failed to open \"" + filename + "\"");

    out << "P6\n" << my_width << " " << my_height << "\n" << color_depth << "\n";

    for (const auto& line : pixels)
    {
        out.write(reinterpret_cast<const char*>(&line[0]), my_width * sizeof(RGB));
    }

    out.close();
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

void Image::blurr()
{
    const int kernel_size = 8;
    float kernel[kernel_size][kernel_size] = { { 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f },
                                               { 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f },
                                               { 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f },
                                               { 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f },
                                               { 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f },
                                               { 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f },
                                               { 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f },
                                               { 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f, 1.0f }};

    float kernel_sum = 64.0f;

    std::vector<std::vector<RGB>> blurred_pixels = pixels;

    for (int y = kernel_size / 2; y < my_height - kernel_size / 2; y++) {
        for (int x = kernel_size / 2; x < my_width - kernel_size / 2; x++) {
            float red_sum = 0.0f;
            float green_sum = 0.0f;
            float blue_sum = 0.0f;

            for (int i = -kernel_size / 2; i <= kernel_size / 2; i++) {
                for (int j = -kernel_size / 2; j <= kernel_size / 2; j++) {
                    red_sum += static_cast<float>(pixels[y + i][x + j].red) * kernel[i + 1][j + 1];
                    green_sum += static_cast<float>(pixels[y + i][x + j].green) * kernel[i + 1][j + 1];
                    blue_sum += static_cast<float>(pixels[y + i][x + j].blue) * kernel[i + 1][j + 1];
                }
            }
            blurred_pixels[y][x].red = static_cast<unsigned char>(red_sum / kernel_sum);
            blurred_pixels[y][x].green = static_cast<unsigned char>(green_sum / kernel_sum);
            blurred_pixels[y][x].blue = static_cast<unsigned char>(blue_sum / kernel_sum);
        }
    }

    pixels = blurred_pixels;
}

void Image::extract_layer(ColorLayer color_layer) {

    for (int w = 0; w <= my_width; w++) {
        for (int h = 0; h < my_height; h++) {
            if (color_layer == ColorLayer::Red) {
                pixels[h][w].green = 0;
                pixels[h][w].blue = 0;
            }
            if (color_layer == ColorLayer::Green) {
                pixels[h][w].red = 0;
                pixels[h][w].blue = 0;
            }
            if (color_layer == ColorLayer::Blue) {
                pixels[h][w].red = 0;
                pixels[h][w].green = 0;
            }
        }
    }
}

void Image::filter() {

    for (int w = 0; w <= (my_width - 1); w++) {
        for (int h = 0; h < (my_height - 1); h++) {
            
            pixels[h][w].red = abs(pixels[h][w].red - pixels[h+1][w+1].red);
            pixels[h][w].green = abs(pixels[h][w].green - pixels[h+1][w+1].green);
            pixels[h][w].blue = abs(pixels[h][w].blue - pixels[h+1][w+1].blue);
        }
    }
}

void Image::flip_horizontally() {

    std::vector<std::vector<RGB>> temp_pixels = pixels;
    
    for (int w = 0; w <= my_width; w++) {
        for (int h = 0; h < my_height; h++) {
            temp_pixels[h][w] = pixels[h][my_width - w];
        }
    }

    pixels = temp_pixels;
}

void Image::flip_vertically() {
    
    std::vector<std::vector<RGB>> temp_pixels = pixels;
    
    for (int w = 0; w <= my_width; w++) {
        for (int h = 0; h < my_height; h++) {
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

    for (int w = 0; w < my_width; w++) {
        for (int h = 0; h < my_height; h++) {
            // ...
        }
    }
}

void Image::sepia() {
    
    std::vector<std::vector<RGB>> temp_pixels = pixels;
    int new_red, new_green, new_blue;

    for (int w = 0; w < my_width; w++) {
        for (int h = 0; h < my_height; h++) {
            
            new_red = round(0.393*pixels[h][w].red + 0.769*pixels[h][w].green + 0.189*pixels[h][w].blue);
            new_green = round(0.349*pixels[h][w].red + 0.686*pixels[h][w].green + 0.168*pixels[h][w].blue);
            new_blue = round(0.272*pixels[h][w].red + 0.534*pixels[h][w].green + 0.131*pixels[h][w].blue);
        
            pixels[h][w].red = (new_red > 255) ? 255 : new_red;
            pixels[h][w].green = (new_green > 255) ? 255 : new_green;
            pixels[h][w].blue = (new_blue > 255) ? 255 : new_blue;
        }
    }
}

void Image::shrink() {

    // ...
}

void Image::to_grayscale() {

    int grayscale = 0;

    for (int w = 0; w < my_width; w++) {
        for (int h = 0; h < my_height; h++) {
            
            grayscale = ((pixels[h][w].red + pixels[h][w].green + pixels[h][w].blue) / 3);
        
            pixels[h][w].red = grayscale;
            pixels[h][w].green = grayscale;
            pixels[h][w].blue = grayscale;
        }
    }
}

int main() {

    Image obrazek;

    obrazek.load("obrazek.ppm");
    // nie dziala obrazek.add_watermark();
    // nie dziala obrazek.blurr();
    // dziala obrazek.extract_layer(ColorLayer::Red);
    // obrazek.filter();
    // nie dziala obrazek.flip_horizontally();
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