#include "comparator.h"

#include <fstream>
#include <sstream>
#include <string>

namespace {
    std::string read_file(const std::string& path) {
        std::ifstream file(path, std::ios::in | std::ios::binary);
        std::ostringstream buffer;
        buffer << file.rdbuf();
        return buffer.str();
    }

    void trim_trailing_whitespace(std::string& s) {
        while (!s.empty()) {
            char ch = s.back();

            if (ch == ' ' || ch == '\n' || ch == '\r' || ch == '\t') {
                s.pop_back();
            }
            else {
                break;
            }
        }
    }
}



bool Comparator::compare(
	const std::string& output_path,
	const std::string& answer_path
) {
    std::string output = read_file(output_path);
    std::string answer = read_file(answer_path);

    trim_trailing_whitespace(output);
    trim_trailing_whitespace(answer);

    return output == answer;
}