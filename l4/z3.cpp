#include <iostream>

// int argc - liczba argumentow podanych w kommand line
// char const *argv[] - tablica charow ktora przechowuje argumenty podane w kommand line
int main(int argc, char const *argv[])
{
    double sum = 0;
    if (argc <=1) throw std::logic_error("No arguments provided, please provide at least one number to sum up"); 

    //jezeli w kommand line znajduje sie --help to wyswietl help
    for (int i=0; i < argc; i++)
    {   
        if ((std::string(argv[i]) == "--help") || (std::string(argv[i]) == "-h"))
        {
        std::cout << "This programme sums up the numbers put in command line for example  1 + 2 + 3 = 6\n";
        return 0;
        }
    }
    for (int i=0; i < argc; i++)
    {   //std::atof - funkcja ktora zamienia string na float
        float v0 = (float)std::atof(argv[i]); 
        sum += v0;
    }
    std::cout << sum <<'\n';
    return 0;  
}
