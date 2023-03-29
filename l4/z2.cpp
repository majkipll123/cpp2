#include <iostream>
#include <cmath>

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
}

int main()
{
    
    double (*f)(double) = [](double x) { return x * x - 2; };
    std::cout << find_root(f, -2, 2) << std::endl;

    return 0;
}