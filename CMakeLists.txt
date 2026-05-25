cmake_minimum_required(VERSION 3.16)

project(oj_judge_core)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${PROJECT_SOURCE_DIR}/include)

add_executable(judge
    src/main.cpp
    src/compiler.cpp
    src/runner.cpp
    src/comparator.cpp
    src/judge.cpp
)