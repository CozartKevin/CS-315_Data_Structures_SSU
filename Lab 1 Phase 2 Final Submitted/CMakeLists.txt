cmake_minimum_required(VERSION 3.10)
project(lab01_2)

set(CMAKE_CXX_STANDARD 17)

add_executable(lab01_2 main.cpp Token.cpp Token.hpp Tokenizer.cpp Tokenizer.hpp TagParser.cpp TagParser.hpp)