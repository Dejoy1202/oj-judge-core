#pragma once

#include <string>

class Compiler {
public:
	bool compile(
		const std::string& source_path,
		const std::string& executable_path,
		const std::string& compile_log_path
	);
};