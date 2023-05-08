#include <iostream>
#include <vector>
#include <algorithm>

struct sort
{
    bool operator()(int a, int b) const
    {
        return (a % 10) < (b % 10);
    }
};

int main()
{
    std::vector<int> v =
    {1, 5, 76, 12, 31, 6, 13, 11, 92, 8};
    std::sort(v.begin(), v.end(), sort());

    for (auto abc = v.begin(); abc != v.end(); ++abc)
    {
        std::cout << *abc << " ";
    }
    return 0;
}
