cmake_minimum_required(VERSION 3.28)
project(geometry)

add_executable(geometryx)
target_sources(geometryx PRIVATE main.cpp fileIn.cpp geometry.cpp)
target_compile_features(geometryx PRIVATE cxx_std_20)
install(TARGET geometryx)
