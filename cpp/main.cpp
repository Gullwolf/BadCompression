//
// Created by George on 17/11/2026.
//
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>


std::vector<std::string> parseFile(std::string fileName) {
    const std::string filePath = "../textFiles/" + fileName + ".txt";
    std::ifstream file(filePath);
    std::vector<std::string> words;
    std::string item;

    if (!file.is_open()) {
        std::cout << "File not found!" << std::endl;
        return {"null"};
    }
    while (file >> item) {
        words.push_back(item);
    }

    return words;
}

std::vector<std::string> removeVowels(std::vector<std::string> words) {
    std::vector<std::string> result;
    for (int i = 0; i < words.size(); i++) {
        std::transform(words[i].begin(), words[i].end(), words[i].begin(), ::toupper);
        words[i].erase(
            std::remove_if(words[i].begin(), words[i].end(),
                           [](char c) {
                               return c == 'A' || c == 'E' || c == 'I' ||
                                      c == 'O' || c == 'U';
                           }),
            words[i].end()
        );
        result.push_back(words[i]);
    }

    return result;
}

int main() {
    std::string fileName;
    std::cout << "Please enter the name of the file you want to open: ";
    std::cin >> fileName;

    std::vector<std::string> test = {parseFile(fileName)};

    test = removeVowels(test);

    for (int i = 0; i < test.size(); i++) {
        std::cout << test[i] << "\n";
    }

    return 0;
}
