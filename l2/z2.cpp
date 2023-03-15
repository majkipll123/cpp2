#include <cstdlib>
#include <complex>
#include <iostream>
void sort(std::complex<double> tab[])
{
    //funkcja qsort ktora pobiera tablice, jej dlugosc oraz rozmiar elementu w tablicy oraz funckję lambda
    //funkcja lambda mowi czy liczba jest mniejsza, wieksza lub rowna drugiej liczbie i na tej podstawie sortuje liczby
    //
    std::qsort(tab, 5, sizeof(std::complex<double>), [](const void* a, const void* b) 
        {// auto i type id i co wydedukuje kompilator
            std::complex<double> x = *static_cast<const std::complex<double>*>(a);
            std::complex<double> y = *static_cast<const std::complex<double>*>(b);
            if (std::abs(x) < std::abs(y))
                return -1;
            else if (std::abs(x) > std::abs(y))
                return 1;
            else
                return 0;
        });

}
int main()
{   
    std::complex<double> tab[5] = { {1000,2},{3,4},{7,8},{9,10},{5,6} };//tablica liczb zespolonych
    sort(tab);
    for (int i = 0; i < 5; i++)
    {
        std::cout << tab[i] << "\n";
    }
    return 0;
}