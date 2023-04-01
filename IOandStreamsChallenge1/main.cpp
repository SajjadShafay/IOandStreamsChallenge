// Section 19
// Challenge 2
// Automated Grader
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <vector>

struct student {
    std::string name{};
    std::string response{};
    int score{};
};

int main() {

    std::ifstream in_file{ "responses.txt" };
    if (!in_file) {
        std::cerr << "File open error" << std::endl;
    }

    std::vector<student> all_students; 
    int count{ 0 };
    std::string key{}; 
    while (!in_file.eof())
    {
        if (count == 0) {
            in_file >> key;
            count++; 
        }
        else {
            student temp;
            in_file >> temp.name;
            in_file >> temp.response;
            all_students.push_back(temp);
        }
    }

    const int name_width{ 30 }, response_width{ 24 }, score_width{ 16 };

    std::cout << "1234567890123456789012345678901234567890123456789012345678901234567890" << std::endl;
    std::cout << "The key is: " << key << std::endl;
    std::cout << std::endl;
    std::cout << std::setw(name_width) << std::left << "Name:"
        << std::setw(response_width) << std::left << "Response:"
        << std::setw(score_width) << std::right << "Score:" << std::endl;
    std::cout << "-----------------------------------------------------------------------" << std::endl;

    float average_score{ 0 };
    for (auto c : all_students)
    {
        for (int i = 0; i <= c.response.size()-1 ; i++)
        {
            if (c.response.at(i) == key.at(i))
                c.score++;
        }

        average_score += c.score; 

        std::cout << std::setw(name_width) << std::left << c.name
            << std::setw(response_width) << std::left << c.response
            << std::setw(score_width) << std::right << c.score << std::endl;
        
    }

    average_score = average_score / all_students.size();
    std::cout << "---------------------------------------------------------------------------" << std::endl;
    std::cout << std::setw(54) << std::left << "Average Score:"
        << std::setw(16) << std::right << average_score << std::endl;

    std::cout << std::endl;
    std::cout << "Hello world" << std::endl;
    return 0;
}

