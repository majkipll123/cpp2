#include <iostream>
#include <cmath>
using namespace std;
float suma(float x)
{
    float s=0;
        for(int j=1;j<=x ;j++ )
        s+=pow(-1,j+1)/(2*j-1);
        s=s*4;
    return s;
}

float iloraz(float y)
{
int j=1;
    float t=1;
        for (int j = 1; j <= y; j++) {
        float licznik = 4 * pow(j, 2);
        float mianownik = 4 * pow(j, 2) - 1;
        t *=  licznik / mianownik;
    } t=t*2;
        return t;
}

float sumapier(float z)
{
    float u=0;
        for(int j=1; j<=z;j++)
        u+=1/(pow(2*j-1,2));
        u=sqrt(8*u);
        return u;

}
int main()
{
    int n = 1000000;
    cout << "Suma szeregu : " << suma(n) << endl;
    cout << "Iloczyn ciągu : " << iloraz(n) << endl;
    cout << "Suma szeregu : " << sumapier(n) << endl;
    return 0;
}
