#include <iostream>
#include <fstream>
#include "JSONTokenizer.hpp"


int main(int argc, char *argv[])
{

    if (argc != 2)
    {  // we expect the name of the file as an argument to the program.
        std::cout << "usage: " << argv[0] << " nameOfAnInputFile" << std::endl;
        exit(1);
    }

    std::ifstream inputStream;
    inputStream.open(argv[1], std::ios::in);    // open for reading
    if( ! inputStream.is_open()) {
        std::cout << "Unable top open " << argv[1] << ". Terminating...";
        exit(2);
    }
    inputStream.close();

    JSONTokenizer jsonTokenizer(argv[1]); // The Tokenizer opens and reads from the input file.

    JSONToken token = jsonTokenizer.getToken();

    while( ! token.endOfFile() ) {
        token.print();
        token = jsonTokenizer.getToken();
    }
}