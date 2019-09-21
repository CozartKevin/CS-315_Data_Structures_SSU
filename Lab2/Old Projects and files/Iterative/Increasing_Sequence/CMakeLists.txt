cmake_minimum_required(VERSION 3.14)
project(Increasing_Sequence)

set(CMAKE_CXX_STANDARD 17)

add_executable(Increasing_Sequence main.cpp read_input.cpp read_input.hpp increasing_sequence_iterative.cpp increasing_sequence_iterative.hpp)