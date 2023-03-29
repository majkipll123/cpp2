#include <iostream>

int main(int argc, char const *argv[])
{
    double sum = 0;
    if (argc <=1) throw std::logic_error("oczekiwano liczby"); 

    //jezeli w kommand line znajduje sie --help to wyswietl help
    for (int i=0; i < argc; i++)
    {   
        if ((std::string(argv[i]) == "--help") || (std::string(argv[i]) == "-h"))
        {
        std::cout << "Program sumuje liczby podane w kommand line\n";
        return 0;
        }
    }
    for (int i=0; i < argc; i++)
    {   
        float v0 = (float)std::atof(argv[i]); 
        sum += v0;
    }
    std::cout << sum <<'\n';
    return 0;
}