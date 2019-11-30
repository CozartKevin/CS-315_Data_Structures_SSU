#include "Token.hpp"
#include "Tokenizer.hpp"
#include "InfixToPostfix.hpp"
#include "numeralParser.hpp"
#include<vector>
#include <fstream>

int main(int argc, char *argv[])
{
    // This function demonstrates the use of the InfixToPostfix class 
    // and its member-function, convert. To that end, the tokens
    // have been hard coded instead of using a tokenizer to 
    // identify them.
    std::vector<Token *> tokens = std::vector<Token *>();
    std::vector<Token *> outputVector = std::vector<Token *>();


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

    std::string toProcess = "";
    while (getline(inputStream, toProcess))
    {
        Tokenizer Tokenizer(toProcess);
        Tokenizer.buildVector(tokens);

        if (tokens.size() > 1)
        {
            std::cout << std::endl;
            Tokenizer.setVariable(tokens, outputVector);
            //TODO: setup assignmentStatementCleanup to reflect call InfixToPostfix syntax
            auto *itop = new InfixToPostfix();
            std::vector<Token *> postfixTokens;
            itop->convert(tokens, postfixTokens);
            std::cout << "\nThe postfix expression has " << postfixTokens.size() << " tokens.\n";

            outputVector[outputVector.size() - 1]->romanNumber(numeralParser::calculateRomanNumeral(
                    postfixTokens)->romanNumber());
        }

        tokens.clear();
    }

    for (unsigned int i = 0; i < outputVector.size(); i++)
    {
        std::cout << outputVector[i]->getVariable() << " equals " << outputVector[i]->romanNumber() << std::endl;
    }

    return 0;
}
