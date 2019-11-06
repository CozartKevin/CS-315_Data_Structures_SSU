cmake_minimum_required(VERSION 3.14.5)
project(Project2)

set(CMAKE_CXX_STANDARD 17)

add_executable(Project2 main.cpp JSONTokenizer.cpp JSONTokenizer.hpp JSONToken.cpp JSONToken.hpp JSONParser.cpp JSONParser.hpp Pair.cpp Pair.hpp EntityInstance.cpp EntityInstance.hpp Entity.cpp Entity.hpp)