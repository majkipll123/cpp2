#include "image.h"
#include "image.cpp"
int main(int argc, char const *argv[])
{
    
    if (argc <=1) throw std::logic_error("No arguments provided, please provide at least one option to use the programe, for help use --help or -h option in command line to see help"); 

    //jezeli w kommand line znajduje sie --help to wyswietl help
    for (int i=0; i < argc; i++)
    {   
        if ((std::string(argv[i]) == "--help") || (std::string(argv[i]) == "-h"))
        {
        std::cout << "This programme has multiple image editing tools and variations,  All of them are listed here: \n height, width, save_as, add_watermark, blurr, extract_layer, filter, flip_horizontally, flip_vertically, inflate, void negative, rotate_clockwise_90, sepia, shrink, to_grayscale\n ";
        }
        
    }

    Image image;
    image.load("obrazek.ppm");
    //image.filter();
    image.save_as("x.ppm");
    return 0;
}
