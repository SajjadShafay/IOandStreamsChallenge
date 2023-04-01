// Section 19
// Challenge 3
// Word counter
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

int main() {

    std::ifstream in_file("romeoandjuliet.txt");
    if (!in_file)
        std::cerr << "File open error" << std::endl;

    std::string line{};

    std::cout << "Please enter a word to find: ";
    std::string word{}, word_lower{}, word_upper{};
    std::cin >> word;

    word_upper = word;
    word_upper[0] = std::toupper(word[0]);
    word_lower = word;
    word_lower[0] = std::tolower(word[0]);

    int num_found{}, num_words{};

    while (!in_file.eof()) {
        in_file >> line;
        if (line.find(word) != std::string::npos || line.find(word_lower) != std::string::npos || line.find(word_upper) != std::string::npos)
            num_found++;
        num_words++;
    }

    std::cout << num_words << " words were searched..." << std::endl;
    std::cout << "The substring " << word << " was found " << num_found << " times" << std::endl;

    return 0;
}