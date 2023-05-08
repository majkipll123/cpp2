#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::vector<int> v =
    {1, 2, 3, 4, 344314, 6, 134134, 59, 6,430};
    std::sort(v.begin(), v.end(), [](int a, int b)
    {
        return (a % 10) < (b % 10);
    });

    for (auto it = v.begin(); it != v.end(); ++it)
    {
        std::cout << *it << " ";
    }
    
    std::cout << std::endl;

    return 0;
}
