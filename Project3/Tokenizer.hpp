//
// Created by Raggdoll on 11/29/2019.
//
#include <string>
#include <fstream>
#include <vector>
#include "Token.hpp"
#ifndef PROJECT1_TOKENIZER_HPP
#define PROJECT1_TOKENIZER_HPP


class Tokenizer {
public:
    Tokenizer(std::string);
    Token *getTokenName();
    void buildVector(std::vector<Token *> &tokens);
private:
    std::string toProcessString;

    bool charOfInterest(char c);
    std::string parseTagName(char c, std::string tagName, std::istream &inputStream) const;

};


#endif //PROJECT1_TOKENIZER_HPP
