#include "runner.h"

#include <cstdlib>
#include <string>

namespace {
	std::string quote(const std::string& path) {
		return "\"" + path + "\"";
	}
}

bool Runner::run(
	const std::string& executable_path,
	const std::string& input_path,
	const std::string& output_path,
	const std::string& runtime_log_path
) {
	std::string command =
		"call " + quote(executable_path)
		+ " < " + quote(input_path)
		+ " > " + quote(output_path)
		+ " 2> " + quote(runtime_log_path);

	int exit_code = std::system(command.c_str());

	return exit_code == 0;
}