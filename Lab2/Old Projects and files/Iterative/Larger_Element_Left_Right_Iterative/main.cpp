#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>
#include "read_input.hpp"
#include "Larger_Elements_Left_Right_iterative.hpp"


int main(int argc, char *argv[])
{
    std::vector<int> vInputNumber;
    std::vector<int> vOutputNumber;

    if (argc != 2)
    {  // we expect the name of the file as an argument to the program.
        std::cout << "usage: " << argv[0] << " nameOfAnInputFile" << std::endl;
        exit(1);
    }

    // Here, we open the file to make sure that it exists before starting the program.
    // When using CLion, the input file has to be in cmake-build-debug directory.
    std::ifstream inputStream;
    inputStream.open(argv[1], std::ios::in);    // open for reading
    if (!inputStream.is_open())
    {
        std::cout << "Unable top open " << argv[1] << ". Terminating...";
        std::cout << strerror(errno) << std::endl;
        exit(2);
    }

    inputStream.close();

    //Reads numbers into vInputNumber Vector
    read_numbers(argv[1],vInputNumber);

vOutputNumber = vInputNumber;
    largest_left_right_iterative(vInputNumber,vOutputNumber);

    //Output vOutputNumber Vector
    for(int v: vOutputNumber){
        std::cout << v << std::endl;
    }

    return 0;
}