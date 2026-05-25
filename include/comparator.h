#pragma once

#include <string>

class Comparator {
public:
	bool compare(
		const std::string& output_path,
		const std::string& answer_path
	);
};