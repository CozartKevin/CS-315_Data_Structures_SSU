cmake_minimum_required(VERSION 3.14)
project(Count_Inversion_Recursive)

set(CMAKE_CXX_STANDARD 17)

add_executable(Count_Inversion_Recursive main.cpp read_input.cpp read_input.hpp count_inversions_recursive.cpp count_inversions_recursive.hpp)