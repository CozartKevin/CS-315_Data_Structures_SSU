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
                                 _isComma{false},
                                 _isCloseBrace{false},
                                 _isDouble{false},
                                 _tagName{""},
                                 _eof{false}{}

bool &JSONToken::isOpenTag() { return _isOpenTag; }
bool &JSONToken::isCloseTag() { return _isCloseTag; }
bool &JSONToken::isOpenBracket(){ return _isOpenBracket; }
bool &JSONToken::isCloseBracket() { return _isCloseBracket; }
bool &JSONToken::isOpenBrace(){ return _isOpenBrace; }
bool &JSONToken::isCloseBrace() { return _isCloseBrace; }
bool &JSONToken::isDouble(){return _isDouble;}
bool &JSONToken::isComma(){return _isComma;}
bool &JSONToken::endOfFile() { return _eof; }


std::string JSONToken::tagName() { return _tagName; }
void JSONToken::makeOpenBrace(std::string name) {
    _isOpenBrace = true;
    _tagName = name;
}
void JSONToken::makeCloseBrace(std::string name){
    _isCloseBrace = true;
    _tagName = name;
}
void JSONToken::makeComma(std::string name){
    _isComma = true;
    _tagName = name;
}
void JSONToken::makeOpenBracket(std::string name){
    _isOpenBracket = true;
    _tagName = name;
};
void JSONToken::makeCloseBracket(std::string name){
    _isCloseBracket = true;
    _tagName = name;
};
void JSONToken::makeDouble(std::string name){
    _isDouble = true;
    _tagName = name;
};
void JSONToken::makeTag(std::string name) {
    _tagName = name;

}
void JSONToken::makeTag(char name) {
    _tagName = name;

}

void JSONToken::print() {

        std::cout << tagName() << std::endl;

}