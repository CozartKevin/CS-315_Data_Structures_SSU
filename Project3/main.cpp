#include "Token.hpp"
#include "InfixToPostfix.hpp"

#include<vector>

int main() {

    // This function demonstrates the use of the InfixToPostfix class 
    // and its member-functionm, convert. To that end, the tokens 
    // have been hard coded instead of using a tokenizer to 
    // identify them.

    std::vector<Token *> tokens = std::vector<Token *>();

    // Suppose that the input contained the following expression.
    // a = XX + XXX  * XXXV + (XXX - XXXII) + II
    // a = 20 + 30 * 35 + (30 + 32) + 2

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
    tokens.push_back(new Token( 'c'));   // 30
    tokens.push_back(new Token(')'));
    tokens.push_back(new Token('+'));
    tokens.push_back(new Token("II"));    // 2
    Token *token = new Token();
    token->eol(true);
    tokens.push_back(token);

    int numTokens = tokens.size();
    std::cout << "The postfix expression (before conversion) has " << numTokens << " tokens.\n";
    for( auto token : tokens )
        token->print();
    std::cout << std::endl;

    InfixToPostfix *itop = new InfixToPostfix();
    std::vector<Token *> postfixTokens;
    itop->convert( tokens, postfixTokens );
    std::cout << "\nThe postfix expression has " << postfixTokens.size() << " tokens.\n";
    for( auto postfixToken : postfixTokens)
        postfixToken->print();
    std::cout << std::endl;

    return 0;
}
