cmake_minimum_required(VERSION 3.6)
project(project1)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        InfixToPostfix.cpp
        main.cpp
        Token.hpp
        InfixToPostfix.cpp
        InfixToPostfix.hpp
        Token.cpp
        TokenIterator.cpp
        TokenIterator.hpp)

add_executable(project1 ${SOURCE_FILES})