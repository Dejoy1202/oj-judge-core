#include "compiler.h"

#include <cstdlib>
#include <filesystem>
#include <string>

namespace {
    std::string quote(const std::string& path) {
        return "\"" + path + "\"";
    }
}


bool Compiler::compile(
    const std::string& source_path,
    const std::string& executable_path,
    const std::string& compile_log_path
) {
    std::filesystem::path exe_path(executable_path);
    std::filesystem::path obj_path = exe_path;
    obj_path.replace_extension(".obj");

    std::string command =
        "cl /nologo /EHsc /std:c++17 "
        + quote(source_path)
        + " /Fe:" + quote(executable_path)
        + " /Fo:" + quote(obj_path.string())
        + " > " + quote(compile_log_path)
        + " 2>&1";

    int exit_code = std::system(command.c_str());

    return exit_code == 0;
}
