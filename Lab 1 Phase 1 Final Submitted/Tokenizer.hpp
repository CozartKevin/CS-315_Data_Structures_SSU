//
// Created by Ali A. Kooshesh on 8/21/18.
//

#ifndef LAB01_2_TOKENIZER_HPP
#define LAB01_2_TOKENIZER_HPP


#include <string>
#include <fstream>
#include "Token.hpp"

class Tokenizer {

public:
    Tokenizer(std::string);
    Token getToken();

private:
    int lineNumber, charPosition;
    std::string inputFileName;
    std::ifstream inputStream;

    bool charOfInterest(char c);

    std::string &getString(char c, std::string &tagName, std::istream &inputStream) const;
};


#endif //LAB01_2_TOKENIZER_HPP
