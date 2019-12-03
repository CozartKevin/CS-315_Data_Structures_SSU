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
    explicit Tokenizer(std::string);

    void buildVector(std::vector<Token *> &tokens);

    static void setVariable(std::vector<Token *> &tokenVector, std::vector<Token *> &outputVector);

private:
    std::string toProcessString;


};


#endif //PROJECT1_TOKENIZER_HPP
