#include <iostream>

int sum(const int tab[], unsigned size)
{
    //funkcja sum przyjmuje tablice i jej rozmiar
    //funkcja sum zwraca sume elementow tablicy
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += tab[i];
    }
    return sum;
}


void sum(const int tab[], unsigned size, int* result)
{
    //funkcja sum przyjmuje tablice, jej rozmiar oraz wskaznik na zmienna w ktora ma zapisac wynik
    //funkcja sum zapisuje sume elementow tablicy do zmiennej wskazywanej przez wskaznik result
    *result = 0;
    for (int i = 0; i < size; i++)
    {
        *result += tab[i];
    }
    std::cout << *result << "\n";
}


void pisz(const int tab[], unsigned size)
{
    //funkcja pisz przyjmuje tablice oraz jej rozmiar
    //funkcja pisz wypisuje elementy tablicy
    for (int i = 0; i < size; i++)
    {
        std::cout << tab[i] << " ";
    }
    std::cout << "\n";
}


void iota(int tab[], unsigned size)
{
    //funkcja iota przyjmuje wskaznik na tablice oraz jej rozmiar
    //funkcja iota wypelnia tablice kolejnymi liczbami naturalnymi
    for (int i = 0; i < size; i++)
    {
        tab[i] = i;
        std::cout<<tab[i]<<" ";
    }
    std::cout<<"\n";
}


void reverse(int * tab, size_t size)
{
    //funkcja reverse przyjmuje wskaznik na tablice oraz jej rozmiar
    //funkcja reverse odwraca kolejnosc elementow tablicy
    for (int i = 0; i < size / 2; i++)
    {
        std::swap(tab[i], tab[size - i - 1]);
    }
    pisz(tab, size);
}


int dot_product(const int* tab1, const int* tab2, size_t size)
{
    //funkcja dot_product przyjmuje dwa wskazniki na tablice oraz jej rozmiar
    //funkcja dot_product zwraca iloczyn skalarny tych tablic
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += tab1[i] * tab2[i];
    }
    return sum;
}

int main()
{ 
    int result=0;
    int tab[10]{ 0,1,2,3,4,5,6,7,8,9 };
    //d
    iota(tab, 10);
    //c
    pisz(tab, 10);
    //e
    reverse(tab, 10);
    //f
    std::cout << dot_product(tab, tab, 10) << "\n";
    //a
    std::cout << sum(tab, 10) << "\n";
    //b
    sum(tab, 10, &result);

    return 0;
}