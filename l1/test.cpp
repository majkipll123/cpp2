#include <iostream>

int main()
{
    int x=1;
    int y=x++;
    int z=--y+x;
    int v=z+=2;
    std::cout<<x<<y<<z<<v<<'\n';
    return 0;
}