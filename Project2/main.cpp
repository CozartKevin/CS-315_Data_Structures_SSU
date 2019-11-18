#include <iostream>
#include <fstream>
#include "JSONTokenizer.hpp"
#include "JSONParser.hpp"

int main(int argc, char *argv[])
{

    if (argc != 3)
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
    std::ifstream inputStream2;
    inputStream2.open(argv[2], std::ios::in);    // open for reading
    if( ! inputStream2.is_open()) {
        std::cout << "Unable top open " << argv[2] << ". Terminating...";
        exit(2);
    }
    inputStream2.close();
    JSONTokenizer jsonTokenizer(argv[1]); // The Tokenizer opens and reads from the input file.
    JSONParser parser(jsonTokenizer);
    Entity testEntity;
  testEntity = parser.parseJSONEntity();

    JSONTokenizer jsonTokenizer2(argv[2]); // The Tokenizer opens and reads from the input file.
    JSONParser parser2(jsonTokenizer2);
    Entity testEntity2;
    testEntity2 = parser2.parseJSONEntity();

Entity outputEntity;
   outputEntity = testEntity.intersection(testEntity2);

    outputEntity.createGPABand();
   outputEntity.printGPABand();
    std::ofstream GPABandOutput;
   GPABandOutput.open ("cs315project2.json");
   outputEntity.outputGPABand(GPABandOutput);
    GPABandOutput.close();

}