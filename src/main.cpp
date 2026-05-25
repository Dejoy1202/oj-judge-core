#include "compiler.h"

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

    std::string executable_path = ".\\sandbox\\main.exe";
    std::string compile_log_path = ".\\sandbox\\compile.log";

    Compiler compiler;
    bool compile_success = compiler.compile(
        source_path,
        executable_path,
        compile_log_path
    );

    if (!compile_success) {
        std::cout << "Compile failed. Result: CE" << std::endl;
        std::cout << "See compile log: " << compile_log_path << std::endl;
        return 1;
    }

    std::cout << "Compile succeeded" << std::endl;
    std::cout << "Executable: " << executable_path << std::endl;

    return 0;
}