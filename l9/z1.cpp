#include <iostream>
#include <vector>

template<typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& vec) {
    for (const auto& element : vec) {
        os << element << " ";
    }
    
    return os;
}

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5};
    std::cout << numbers << std::endl;
    std::vector<std::string> names = {"Karol", "Kabulon"};
    std::cout << names << std::endl;
    std::vector<double> doubles = {1.1, 2.2, 3.3};
    std::cout << doubles << std::endl;
    std::vector<float> floats = {1.1 , 2.3, 3.4};
    std::cout << floats << std::endl; 

    return 0;
}
