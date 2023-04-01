// Section 19
// Challenge 4
// Copy Romeo and Juliet with line numbers
#include <iostream>
#include <fstream>
#include <string>

int main() {
    
    std::ifstream in_file{ "romeoandjuliet" }; 
    if (!in_file)
        std::cerr << "couldn't open input file" << std::endl;

    std::ofstream out_file{ "output.txt" };
    if (!out_file)
        std::cerr << "couldn't open output file" << std::endl;

    std::string line{};
    int count{1}; 
    while (!in_file.eof())
    {
        // only add a line number to lines that have text
        std::getline(in_file, line);
        if (line.size() != 0) {
            out_file << count << "          " << line << std::endl;
            count++;
        }
        else
            out_file << line << std::endl;

        // add a line number to every line even blank lines
        //out_file << count << "          " << line << std::endl;
       
    }
   
    return 0;
}

