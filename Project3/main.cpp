#include "Token.hpp"
#include "Tokenizer.hpp"
#include "InfixToPostfix.hpp"
#include "numeralParser.hpp"
#include<vector>
#include <fstream>

int main(int argc, char *argv[])
{
//File Checking
    if (argc != 2)
    {  // we expect the name of the file as an argument to the program.
        std::cout << "usage: " << argv[0] << " nameOfAnInputFile" << std::endl;
        exit(1);
    }

    std::ifstream inputStream;
    inputStream.open(argv[1], std::ios::in);    // open for reading
    if (!inputStream.is_open())
    {
        std::cout << "Unable top open " << argv[1] << ". Terminating...";
        std::cout << strerror(errno) << std::endl;
        exit(2);
    }
//Vector Generation
    std::vector<Token *> tokens = std::vector<Token *>();
    std::vector<Token *> outputVector = std::vector<Token *>();

    std::string toProcess;

    while (getline(inputStream, toProcess))
    {
        Tokenizer Tokenizer(toProcess);
        Tokenizer.buildVector(tokens);
        if(tokens[0]->isAVariable())
        {

        for( auto token : tokens )
            token->print();
        std::cout << std::endl;

        if (tokens.size() > 1)
        {
            Tokenizer.setVariable(tokens, outputVector);

                auto *itop = new InfixToPostfix();
                std::vector<Token *> postfixTokens;
                itop->convert(tokens, postfixTokens);

                outputVector[outputVector.size() - 1]->romanNumber(numeralParser::calculateRomanNumeral(
                        postfixTokens)->romanNumber());
        }
        }else{
            std::cout << " There is no variable in the assignment statement." << std::endl;

            for( auto token : tokens )
                token->print();
            std::cout << std::endl;

            std::cout << "Exiting Program" << std::endl;
            exit(1);
        }
        tokens.clear();
    }
    std::cout << std::endl;
    for (unsigned int i = 0; i < outputVector.size(); i++)
    {
        std::cout << outputVector[i]->getVariable() << " equals " << outputVector[i]->romanNumber() << std::endl;
    }

    return 0;
}
