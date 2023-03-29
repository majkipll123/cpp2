#include <iostream>
#include <vector>
//obciążenie operatora * po to zeby wyswietlal iloczyn skalarny wektorow

class Vector
{
    public:

    Vector(int x, int y, int z)
    //konstruktor klasy Vector
    {
        this->x = x;
        this->y = y;
        this->z = z;
    }
    //deklaracja zmiennych klasy Vector 
    int x;
    int y;
    int z;

    int operator*(Vector v) 
    //obciazenie operatora * po to zeby wyswietlal iloczyn skalarny wektorow
    {
        return (this->x * v.x) + (this->y * v.y) + (this->z * v.z);
    }
};

int main()
{
    Vector v1(1,2,3);
    Vector v2(4,5,6);
    std::cout << v1 * v2 << std::endl;


    return 0;
}