cmake_minimum_required(VERSION 3.28)
project(lab12)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(${PROJECT_NAME} main.cpp sorts.hpp)

add_compile_options(
    -Werror
    -Wall
    -Wextra
    -Wpedantic
)
if (DEBUG)
    add_compile_options(-g -ggdb)
    add_compile_definitions(DEGUB)
endif()