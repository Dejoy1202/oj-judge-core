#pragma once

#include <string>

class Runner {
public:
	bool run(
		const std::string& executable_path,
		const std::string& input_path,
		const std::string& output_path,
		const std::string& runtime_log_path
	);
};