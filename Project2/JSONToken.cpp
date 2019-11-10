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
                                 _isNumber{false},
                                 _isColon{false},
                                 _isString{false},
                                 _tagName{""},
                                 _eof{false}{}

bool &JSONToken::isOpenTag() { return _isOpenTag; }
bool &JSONToken::isCloseTag() { return _isCloseTag; }
bool &JSONToken::isOpenBracket(){ return _isOpenBracket; }
bool &JSONToken::isCloseBracket() { return _isCloseBracket; }
bool &JSONToken::isOpenBrace(){ return _isOpenBrace; }
bool &JSONToken::isCloseBrace() { return _isCloseBrace; }
bool &JSONToken::isNumber(){return _isNumber;}
bool &JSONToken::isString(){return _isString;}
bool &JSONToken::isComma(){return _isComma;}
bool &JSONToken::isColon(){return _isColon;}
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
}
void JSONToken::makeCloseBracket(std::string name){
    _isCloseBracket = true;
    _tagName = name;
}
void JSONToken::makeNumber(std::string name){
    _isNumber = true;
    _tagName = name;
}
void JSONToken::makeColon(std::string name) {
    _isColon = true;
    _tagName = name;

}
void JSONToken::makeString(std::string name) {
    _isString = true;
    _tagName = name;

}
double JSONToken::toDouble()
{
    return std::stod(_tagName);
}

void JSONToken::print() {

        std::cout << tagName() << std::endl;

}