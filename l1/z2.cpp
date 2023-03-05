#include <iostream>
#include <cmath>
using namespace std;
float pi1(float i)
{
    double T= 1.0 / sqrt(3.0);

    for (int n = 0 ; n < i; n++)
    {
    T=(sqrt(pow(T,2)+1)-1)/T;
    }
    return 6*pow(2,i)*T;
    }
    float pi2(float i)
{
    double T= 1.0 / sqrt(3.0);

    for (int n = 0 ; n < i; n++)
    {
    T=T/(sqrt(pow(T,2)+1)+1);
    }
    return 6*pow(2,i)*T;
    }
int main()
{

    for (int n=0; n<=30;n++)
    cout<<pi1(n)<<endl;
    cout<<" nowa fala "<<endl;
    for (int n=0; n<=30;n++)
    cout<<pi2(n)<<endl;



return 0;
}
