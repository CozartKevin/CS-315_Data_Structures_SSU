//
// Created by Raggdoll on 11/3/2019.
//
#include <iostream>
#include "JSONToken.hpp"
JSONToken::JSONToken(): _isOpenTag{false},
                                 _isCloseTag{false},
                                 _isCloseBracket{false},
                                 _isOpenBracket{false},
                                 _isOpenBrace{false},
                                 _isCloseBrace{false},
                                 _tagName{""},
                                 _eof{false}{}

bool &JSONToken::isOpenTag() { return _isOpenTag; }
bool &JSONToken::isCloseTag() { return _isCloseTag; }
bool &JSONToken::isOpenBracket(){ return _isOpenBracket; }
bool &JSONToken::isCloseBracket() { return _isCloseBracket; }
bool &JSONToken::isOpenBrace(){ return _isOpenBrace; }
bool &JSONToken::isCloseBrace() { return _isCloseBrace; }
bool &JSONToken::endOfFile() { return _eof; }


std::string JSONToken::tagName() { return _tagName; }

void JSONToken::makeTag(std::string name) {
    _tagName = name;

}
void JSONToken::makeTag(char name) {
    _tagName = name;

}

void JSONToken::print() {

        std::cout << tagName() << std::endl;

}