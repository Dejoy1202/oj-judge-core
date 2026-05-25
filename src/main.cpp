#include <iostream>
#include<filesystem>
#include<string>

int main(int argc, char* argv[]) {
    std::cout << "OJ Judge Core started." << std::endl;

    if (argc != 4) {
        std::cout << "Usage: judge <source.cpp> <input.txt> <answer.txt>" << std::endl;
        return 1;
    }

    std::string source_path = argv[1];
    std::string input_path = argv[2];
    std::string answer_path = argv[3];

    std::cout << "Source: " << source_path << std::endl;
    std::cout << "Input : " << input_path << std::endl;
    std::cout << "Answer: " << answer_path << std::endl;

    if (!std::filesystem::exists(source_path)) {
        std::cout << "Source file not found: " << source_path << std::endl;
        return 1;
    }
    if (!std::filesystem::exists(input_path)) {
        std::cout << "Input file not found: " << input_path << std::endl;
        return 1;
    }
    if (!std::filesystem::exists(answer_path)) {
        std::cout << "Answer file not found: " << answer_path << std::endl;
        return 1;
    }

    std::cout << "All input files exist." << std::endl;
    std::cout << "Day 1 check passed" << std::endl;

    return 0;
}