#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iterator>
#include <ctime>

template<typename T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& vec) {
    for (const auto& element : vec)
        os << element << " ";

    return os;
}

int main() {
    std::vector<int> vector1(10);
    std::vector<int> vector2(10); //ustawianie rozmiaru wektorów

    std::iota(vector1.begin(), vector1.end(), 0); //Zapisuje kolejne liczby naturalne od 0 do 9 w vector1
    std::cout << vector1 << std::endl;

    int sum = std::accumulate(vector1.begin(), vector1.end(), 0); //Oblicza sumę wartości elementów vector1
    std::cout << "Suma: " << sum << std::endl;

    std::transform(vector1.begin(), vector1.end(), vector1.begin(), [](int n) { return n * n; }); //Zamienia każdą liczbę na jej kwadrat poprzez funkcję lambda
    std::cout << vector1 << std::endl;

    std::srand(std::time(0)); // Inicjalizacja generatora liczb pseudolosowych

    std::generate(vector2.begin(), vector2.end(), []() { return std::rand() % 15; }); //Generuje liczby losowe z zakresu od 0 do 14 w vector2
    std::cout << vector2 << std::endl;

    int maxElement = *std::max_element(vector2.begin(), vector2.end()); //Znajduje maksymalny element w vector2
    std::cout << "Max = " << maxElement << std::endl;

    std::sort(vector2.begin(), vector2.end()); //Sortuje elementy od najmniejszego do największego w vector2
    std::cout << vector2 << std::endl;

    vector2.erase(std::unique(vector2.begin(), vector2.end()), vector2.end()); //Usuwa duplikaty z vector2
    std::cout << vector2 << std::endl;

    std::vector<int> vec3;
    std::set_intersection(vector1.begin(), vector1.end(), vector2.begin(), vector2.end(), std::back_inserter(vec3)); //Tworzy trzeci wektor vec3 z iloczynem mnogościowym
    std::cout << vec3 << std::endl;

    return 0;
}
