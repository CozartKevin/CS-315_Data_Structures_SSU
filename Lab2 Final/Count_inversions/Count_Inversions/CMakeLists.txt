cmake_minimum_required(VERSION 3.14)
project(Count_Inversions)

set(CMAKE_CXX_STANDARD 17)

add_executable(Count_Inversions main.cpp read_input.cpp read_input.hpp count_inversions_iterative.cpp count_inversions_iterative.hpp)