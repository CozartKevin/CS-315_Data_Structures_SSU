#include "Token.hpp"
#include "InfixToPostfix.hpp"
#include "numeralParser.hpp"
#include "assignmentStatementCleanup.hpp"
#include<vector>

int main() {

    // This function demonstrates the use of the InfixToPostfix class 
    // and its member-function, convert. To that end, the tokens
    // have been hard coded instead of using a tokenizer to 
    // identify them.

    std::vector<Token *> tokens = std::vector<Token *>();
    std::vector<Token *> tokens2 = std::vector<Token *>();
    std::vector<Token *> outputVector = std::vector<Token *>();

    // Suppose that the input contained the following expression.
    // a = XX + XXX  * XXXV + (XXX - XXXII) + II
    // a = 20 + 30 * 35 + (30 - 32) + 2
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
    */
    tokens.push_back(new Token('b'));     // variable c
    tokens.push_back(new Token('='));     //
    tokens.push_back(new Token("XII"));
    Token *token = new Token();
    token->eol(true);
    tokens.push_back(token);

    int numTokens = tokens.size();
    std::cout << "The postfix expression (before conversion) has " << numTokens << " tokens.\n";
    for( auto token : tokens )
        token->print();
    std::cout << std::endl;
    assignmentStatementCleanup::setVariable(tokens,outputVector);
    //TODO: setup assignmentStatementCleanup to reflect call InfixToPostfix syntax
    InfixToPostfix *itop = new InfixToPostfix();
    std::vector<Token *> postfixTokens;
    itop->convert( tokens, postfixTokens );
    std::cout << "\nThe postfix expression has " << postfixTokens.size() << " tokens.\n";
    for( auto postfixToken : postfixTokens)
        postfixToken->print();
    std::cout << std::endl;

       // outputVector.push_back(numeralParser::calculateRomanNumeral(postfixTokens));
        outputVector[outputVector.size() - 1]->romanNumber(numeralParser::calculateRomanNumeral(postfixTokens)->romanNumber());    //TODO: setup numeralParser to reflect call InfixToPostfix calls see previous TODO


        for(unsigned int i = 0; i < outputVector.size(); i++){
            std::cout << outputVector[i]->getVariable() << " equals " << outputVector[i]->romanNumber() << std::endl;
        }
    for( auto token : outputVector)
        token->print();
    std::cout << std::endl;

    //TODO: deleted below after implementation the loop from file

    tokens2.push_back(new Token('c'));     // variable c
    tokens2.push_back(new Token('='));     //
    tokens2.push_back(new Token("MMDCCCLXXXVIII"));
    tokens2.push_back(new Token('+'));
    tokens2.push_back(new Token( 'b'));  // variable b

    Token *token2 = new Token();
    token2->eol(true);
    tokens2.push_back(token2);

    int numTokens2 = tokens2.size();
    std::cout << "The postfix expression (before conversion) has " << numTokens << " tokens.\n";
    for( auto token : tokens2 )
        token->print();
    std::cout << std::endl;
    assignmentStatementCleanup::setVariable(tokens2,outputVector);


    InfixToPostfix *itop2 = new InfixToPostfix();
    std::vector<Token *> postfixTokens2;
    itop->convert( tokens2, postfixTokens2 );
    std::cout << "\nThe postfix expression has " << postfixTokens.size() << " tokens.\n";
    for( auto postfixToken2 : postfixTokens2)
        postfixToken2->print();
    std::cout << std::endl;

    // outputVector.push_back(numeralParser::calculateRomanNumeral(postfixTokens));
    outputVector[outputVector.size() - 1]->romanNumber(numeralParser::calculateRomanNumeral(postfixTokens2)->romanNumber());


    for(unsigned int i = 0; i < outputVector.size(); i++){
        std::cout << outputVector[i]->getVariable() << " equals " << outputVector[i]->romanNumber() << std::endl;
    }
    for( auto token : outputVector)
        token->print();
    std::cout << std::endl;

//TODO: create loop for entire program, that takes assignment statements (from a file?) and processes each into the outputVector until no more assignment statements
//TODO: Print ouputVector after all assignment statements are processed



    return 0;
}
