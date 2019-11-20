
#ifndef __TokenIterator
#define __TokenIterator

#include<vector>
#include "Token.hpp"

class TokenIterator {  

public:
    TokenIterator( std::vector<Token *> &tokens );
    Token  *next();   // provides access to the next token. 
    void put_back();  // At times, we will have to look at the next token 
                      // to know if we can process it or it should be put
                      // back so that another entity would use it.

    void printProcessedTokens(); // Prints tokens in orders
    bool hasMoreTokens();  // Do we have at least one more token to dispense?
    ~TokenIterator();

private:
    std::vector<Token  *> tokens;
    int cur, numTokens;
};

#endif
