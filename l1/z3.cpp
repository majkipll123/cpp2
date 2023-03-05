#include <iostream>
using namespace std;

double dbdown(int n)
{
    double suma=0;
    for(int i; i<=n; i++)
        suma+=1/i;
    return suma;
}

double dbup(int n)
{
    double suma=0;
    for (int i=1; n>=i; n--)
        suma+=1/n;
    return suma;
}
float dtdown(int n)
{
    float suma=0;
    for(int i; i<=n; i++)
        suma+=1/i;
    return suma;
}

float ftup(int n)
{
    float suma=0;
    for (int i=1; n>=i; n--)
        suma+=1/n;
    return suma;
}


int main()
{
    int n=100000000;

    int o=100000;

    int p=100;

    cout<<dbup(n)-dbdown(n)<<"\n";
    cout<<dbup(o)-dbdown(o)<<"\n";
    cout<<dbup(p)-dbdown(p)<<"\n";

    cout<<ftup(n)-dtdown(n)<<"\n";
    cout<<ftup(o)-dtdown(o)<<"\n";
    cout<<ftup(p)-dtdown(p)<<"\n";

    return 0;
}
