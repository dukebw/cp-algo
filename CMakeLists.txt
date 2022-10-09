cmake_minimum_required(VERSION 3.24)
project(codeforces VERSION 0.0.1 LANGUAGES CXX)

add_executable(shortestpath src/codeforces/shortestpath.cpp)
target_compile_features(shortestpath PRIVATE cxx_std_20)
