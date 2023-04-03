#include <iostream>
#include <cmath>
// double(*f)(double) - wskaznik do funkcji ktora przyjmuje double i zwraca double
double find_root(double(*f)(double), double a, double b, double tolerance = 1e-10)
{
    double x = (a + b)/ 2; // sprawdzenie czy x jest w przedziale oraz czy jest pierwiastkiem rownania 


    
    // (czy f(x) jest rowne 0) 
    // jesli nie to sprawdzamy czy f(a) * f(x) < 0
    // jesli tak to znaczy ze pierwiastek jest w przedziale (a, x)
    // jesli nie to znaczy ze pierwiastek jest w przedziale (x, b)
    // po osiagnieciu zadanej dokladnosci algorytm konczy dzialanie a szukany pierwiastek rownania wynosi a+b/2
    
    while (std::abs(f(x)) > tolerance)
    {
        if (f(a) * f(x) < 0)
        {
            b = x;
        }
        else
        {
            a = x;
        }
        x = (a + b) / 2;
    }
    
    return x;
}

int main()
{ //deklaracja funkcji f ktora przyjmuje dobule i zwraca wartosc double 

    auto  f = [](double x) {return cos(x) - x;}; 
    auto f2 = [](double x) {return cos(x)-0.5;}; 
    // w tej linijce funkcja f jest zdefiniowana jako lambda expression czyli []
    // [] - argumenty funkcji w tym wypadku nie trzeba ich podawac poniewaz nawias jest pusty
    // {} - cialo funkcji w tym 

    std::cout << "the root of cos(x)=x in [0,2] is "<<find_root(f, 0, 2) <<"\n";
    std::cout <<"the root of cos(x)=0.5 in [0,1.5] is " <<find_root(f2, 0, 1.5) <<"\n";

    return 0;
}