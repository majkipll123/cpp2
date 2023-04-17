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

void add_watermark()
{
    std::cout << "add_watermark procedure sterted " << std::endl;

    Image image;
    image.load("obrazek.ppm");
    image.filter();
    image.save_as("xwatermark.ppm");

    std::cout << "add_watermark procedure finished " << std::endl;
}


    void blurr();
    void extract_layer(ColorLayer color_layer)
    //ten layer ma byc wyciagniety poprzez zerowanie 2 z 3 skladwoych kolorow 
    {
        std::cout << "extract_layer procedure sterted " << std::endl;

        Image image;
        image.load("obrazek.ppm");
        
        image.save_as("xextract_layer.ppm");

        std::cout << "extract_layer procedure finished " << std::endl;
    }
    void filter();
    void flip_horizontally();
    void flip_vertically();
    void inflate();
    void negative();


void rotate_clockwise_90()
{
    std::cout << "rotate_clockwise_90 procedure sterted " << std::endl;

    Image image;
    image.load("obrazek.ppm");
    
    image.save_as("xrotate_clockwise_90.ppm");

    std::cout << "rotate_clockwise_90 procedure finished " << std::endl;
}
    void sepia();
    void shrink();
    void to_grayscale();