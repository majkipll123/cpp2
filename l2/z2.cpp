#include <cstdlib>
#include <complex>
#include <iostream>
void sort(std::complex<double> tab[])
{
    std::qsort(tab, 5, sizeof(std::complex<double>), [](const void* a, const void* b) -> int
        {
            std::complex<double> x = *(std::complex<double>*)a;
            std::complex<double> y = *(std::complex<double>*)b;
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
    std::complex<double> tab[5] = { {444,2},{27,4},{7,8},{9,10},{5,6} };
    qsort(tab);
    for (int i = 0; i < 5; i++)
    {
        std::cout << tab[i] << "\n";
    }
    return 0;
}