#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <algorithm>
#include <cctype>

std::string removePunctuation(const std::string& word) {
    std::string result;
    std::copy_if(word.begin(), word.end(), std::back_inserter(result), [](char c) {
        return std::isalnum(c) || c == '-' || c == '\'';
    });
    
    return result;
}

int main() {
    std::ifstream file("tekst.txt");
    std::string word;
    std::map<std::string, int> wordCount;

    while (file >> word) {
        word = removePunctuation(word);

        if (!word.empty()) {
            ++wordCount[word];
        }
    }

    file.close();

    std::multimap<int, std::string, std::greater<int>> sortedWords;

    for (const auto& pair : wordCount) {
        sortedWords.insert(std::make_pair(pair.second, pair.first));
    }

    int wordNumber = 1;

    for (const auto& pair : sortedWords) {
        std::cout << wordNumber << ".\t" << pair.second << ":\t" << pair.first << std::endl;
        
        ++wordNumber;
    }

    return 0;
}
