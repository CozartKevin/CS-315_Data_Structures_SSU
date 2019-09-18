//
// Created by Ali A. Kooshesh on 8/21/18.
// Leveraged By Kevin J. Cozart
//

#include <iostream>
#include <iomanip>
#include "Token.hpp"


Token::Token(int line, int pos): _isOpenTag{false},
                                 _isCloseTag{false},
                                 _isCloseAngleBracket{false},
                                 _isOpenAngleBracket{false},
                                 _isCloseStandAloneTag{false},
                                 _eof{false},
                                 _tagName{""},
                                 _lineNumber{line},
                                 _charPos{pos} {}

bool &Token::isOpenTag() { return _isOpenTag; }
bool &Token::isCloseTag() { return _isCloseTag; }

bool &Token::isCloseAngleBracket() { return _isCloseAngleBracket; }
bool &Token::isOpenAngleBracket(){ return _isOpenAngleBracket;}
bool &Token::endOfFile() { return _eof; }
bool &Token::isCloseStandAloneTag() { return _isCloseStandAloneTag; }

std::string Token::tagName() { return _tagName; }

void Token::makeOpenTag(std::string name) {
    _tagName = name;
    isOpenTag() = true;

}

void Token::makeCloseTag(std::string name) {
    _tagName = name;
    isCloseTag() = true;

}
void Token::makeStandAloneCloseTag(std::string name) {
    _tagName = name;
    isCloseStandAloneTag() = true;

}
void Token::makeClosedAngleBracket(std::string name){
    _tagName = name;
    isCloseAngleBracket() = true;
}
void Token::makeOpenAngleBracket(std::string name){
    _tagName = name;
    isOpenAngleBracket() = true;
}

void Token::print() {

    if(isOpenTag()) {
        printLineandCharPos();
        std::cout << "<" << tagName();
    }else if(isCloseTag()){
        printLineandCharPos();
        std::cout << "</" << tagName();
    }else if(isCloseStandAloneTag()) {
        printLineandCharPos();
        //std::cout << "[" << _lineNumber << ", " << _charPos << "] ";
        std::cout << tagName();
    }else if(isCloseAngleBracket()){
        printLineandCharPos();
        std::cout << tagName();
    }else if(isOpenAngleBracket()){
        printLineandCharPos();
        std::cout << tagName();
    }else{

        std::cout<<std::endl;
return;
    }
    // ...
}

void Token::printLineandCharPos() const
{ std::cout << "[" << std::setw(2) << _lineNumber << ", " << std::setw(3) << _charPos << "] "; }
