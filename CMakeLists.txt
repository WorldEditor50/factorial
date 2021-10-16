cmake_minimum_required(VERSION 3.5)

project(factorial LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
# factorial
add_library(LargeInt
    ${PROJECT_SOURCE_DIR}/largeint.h
    ${PROJECT_SOURCE_DIR}/largeint.cpp)
add_executable(factorial main.cpp)
target_link_libraries(factorial LargeInt)
