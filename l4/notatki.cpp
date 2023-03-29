#include <iostream>
#include <vector>
class Vector
{   
    public:
        Vector(int n)// to jest konstruktor poniewaz ma ta sama nazwe jak klasa
        //fukncja ktora jest wykorzystywana podczas tworzenia obiektu
        // ten : wprowadza liste inicjalizacyjna konstruktora 
        // w ktorej mozna zainicjalizowac zmienne
        :size{n}
        {
            size = n;
            
        }
        int size;
        
};

int main() 
{
    int n=9;
    std::vector<int> w(9);
    Vector v(9);
    return 0;
}