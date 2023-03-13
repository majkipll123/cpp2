#include <iostream>
#include <complex>
#include <algorithm>

void sort(std::complex<double> tab[], int size) {
    std::sort(tab, tab + size, [](const std::complex<double>& a, const std::complex<double>& b) {
        return a.imag() < b.imag();
    });
    // w kodzie funkcja sort ma argument typu bool ascending ktory okresla czy licby maja byc sortowane w porzadku malejacym czy rosnacym
    // jesli ascending == true to sortowanie ma byc rosnace a jesli ascending == false to sortowanie ma byc malejace
    //domysnie sortuje od najwiekszej do najmniejszej do najwiekszej
    // funkcja std::sort uzywa wyrażenia funckji które przekazujemy jako lambda [](const std..itd) a nestepnie 
    //definiuje w jaki sposob te liczby maja byc porownywane
}

int main() {
    std::complex<double> tab[5] = {{444, 2}, {27, 4}, {7, 8}, {9, 10}, {5, 6}};
    int size = sizeof(tab) / sizeof(tab[0]);
    //Linijka int size = sizeof(tab) / sizeof(tab[0]); służy do obliczenia liczby elementów w tablicy tab. 
    //Wynik działania wyrażenia sizeof(tab) to liczba bajtów zajmowanych przez całą tablicę, a wynik wyrażenia sizeof(tab[0]) to liczba bajtów zajmowanych przez pojedynczy element tablicy. 
    //Podzielając wynik pierwszego wyrażenia przez wynik drugiego wyrażenia, otrzymujemy liczbę elementów w tablicy.
    //wykorzystuje go poniewaz jest to uniwersalne dla typow danych w tablicy i nie musze podawac jej rozmiaru oraz nie musze zmieniac kodu jesli zmienie rozmiar tablicy
    // poniewaz jest ona automatycznie wyliczana
    sort(tab, size);

    for (int i = 0; i < size; i++) {
        std::cout << tab[i] << "\n";
    }

    return 0;
}