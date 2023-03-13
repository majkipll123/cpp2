#include <iostream>

double dbdown(int n)
{
    double sum=0;
    for(int i; i<=n; i++)
        sum+=1/i;
    return sum;
}

double dbup(int n)
{
    double sum=0;
    for (int i=1; n>=i; n--)
        sum+=1/n;
    return sum;
}
float dtdown(int n)
{
    float sum=0;
    for(int i; i<=n; i++)
        sum+=1/i;
    return sum;
}

float ftup(int n)
{
    float sum=0;
    for (int i=1; n>=i; n--)
        sum+=1/n;
    return sum;
}


int main()
{
    int n=100000000;

    int o=100000;

    int p=100;

    std::cout<<dbup(n)-dbdown(n)<<"\n";
    std::cout<<dbup(o)-dbdown(o)<<"\n";
    std::cout<<dbup(p)-dbdown(p)<<"\n";

    std::cout<<ftup(n)-dtdown(n)<<"\n";
    std::cout<<ftup(o)-dtdown(o)<<"\n";
    std::cout<<ftup(p)-dtdown(p)<<"\n";

    return 0;
}
