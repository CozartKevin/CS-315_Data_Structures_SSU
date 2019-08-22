//
// Created by Ali A. Kooshesh on 8/21/18.
//

#include <iostream>
#include "Tokenizer.hpp"

Tokenizer::Tokenizer(std::string name): lineNumber{1},
                                        charPosition{1},
                                        inputFileName{name} {
    inputStream.open(inputFileName, std::ios::in);  // open the input file. We will make sure that it is open in getToken.
}

bool Tokenizer::charOfInterest(char c) {
    // is c the initial (or the sole) character of a token?

    return true;   // you need to replace this with code that compares c with characters like '<', '>', etc.
}

Token Tokenizer::getToken() {
    char c;

    if( ! inputStream.is_open()) {
        std::cout << "Tokenizer::getToken() called with a stream that is not open." << std::endl;
        std::cout << "Make sure that " << inputFileName << " exists and is readable. Terminating.";
        exit(2);
    }

    while( inputStream.get(c) && ! charOfInterest(c) ) {
        // keep track of the line number and the character position
    }

    Token token(lineNumber, charPosition);
    if( inputStream.eof() ) {
        token.endOfFile() = true;
        return token;
    }

    if( c == '<' ) { // A possible open tag.
        // suppose we have found an open em-tag.
        token.makeOpenTag("em");
        return token;
    } else if( c == '>' ) {
        token.isCloseAngleBracket() = true;
        return token;
    } // ... more if-else statements here.


    return token;
}