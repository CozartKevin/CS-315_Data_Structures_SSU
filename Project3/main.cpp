#include "Token.hpp"
#include "Tokenizer.hpp"
#include "InfixToPostfix.hpp"
#include "numeralParser.hpp"
#include "assignmentStatementCleanup.hpp"
#include<vector>
#include <fstream>
int main (int argc, char *argv[]) {

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
   // inputStream.close();


    std::string toProcess = "";
    while(getline(inputStream,toProcess))
{
        Tokenizer Tokenizer(toProcess);
        Tokenizer.buildVector(tokens);
/*

    tokens.push_back(new Token('a'));     // variable a
   tokens.push_back(new Token('='));     //
    tokens.push_back(new Token("XX"));     // 20
    tokens.push_back(new Token('+'));
    tokens.push_back(new Token( "XXX"));  // 30
    tokens.push_back(new Token('*'));
    tokens.push_back(new Token( "XXXV"));  // 35
    tokens.push_back(new Token('+'));
    tokens.push_back(new Token('('));
    tokens.push_back(new Token("XXXII"));  // 32
    tokens.push_back(new Token('-'));
    tokens.push_back(new Token( "XXX"));   // 30
    tokens.push_back(new Token(')'));
    tokens.push_back(new Token('+'));
    tokens.push_back(new Token("II"));    // 2
    Token *token = new Token();
    token->eol(true);
    tokens.push_back(token);
    tokens.push_back(new Token('b'));     // variable c
    tokens.push_back(new Token('='));     //
    tokens.push_back(new Token("XII"));
    Token *token = new Token();
    token->eol(true);
    tokens.push_back(token);
*/
    int numTokens = tokens.size();

    std::cout << "The postfix expression (before conversion) has " << numTokens << " tokens.\n";
    for (auto token : tokens)
    {
        token->print();
        std::cout << " token" << std::endl;
    }
    std::cout << std::endl;
    assignmentStatementCleanup::setVariable(tokens, outputVector);
    //TODO: setup assignmentStatementCleanup to reflect call InfixToPostfix syntax
    InfixToPostfix *itop = new InfixToPostfix();
    std::vector<Token *> postfixTokens;
    itop->convert(tokens, postfixTokens);
    std::cout << "\nThe postfix expression has " << postfixTokens.size() << " tokens.\n";
    for (auto postfixToken : postfixTokens)
        postfixToken->print();
    std::cout << std::endl;

    // outputVector.push_back(numeralParser::calculateRomanNumeral(postfixTokens));
    outputVector[outputVector.size() - 1]->romanNumber(numeralParser::calculateRomanNumeral(
            postfixTokens)->romanNumber());    //TODO: setup numeralParser to reflect call InfixToPostfix calls see previous TODO


              tokens.clear();



    for(unsigned int i = 0; i < outputVector.size(); i++){
        std::cout << outputVector[i]->getVariable() << " equals " << outputVector[i]->romanNumber() << std::endl;
    }
  //  if(inputStream.peek() == '\n'){
   //     inputStream.get();
   // }
}





//TODO: create loop for entire program, that takes assignment statements (from a file?) and processes each into the outputVector until no more assignment statements
//TODO: Print ouputVector after all assignment statements are processed



    return 0;
}
