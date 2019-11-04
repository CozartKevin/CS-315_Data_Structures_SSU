//
// Created by Raggdoll on 11/3/2019.
//

#ifndef PROJECT2_JSONTOKEN_HPP
#define PROJECT2_JSONTOKEN_HPP
#include <string>

class JSONToken {

public:
    JSONToken();
    bool &isOpenTag();
    bool &isCloseTag();
    bool &isCloseBracket();
    bool &isOpenBracket();
    bool &isOpenBrace();
    bool &isCloseBrace();
    bool &endOfFile();


    std::string tagName();

    void makeTag(std::string);
    void makeTag(char);
    void print();

private:
    bool _isOpenTag, _isCloseTag,_isOpenBracket, _isCloseBracket, _isCloseBrace, _isOpenBrace,
            _eof ;

    std::string _tagName;
    int _lineNumber, _charPos;


};




#endif //PROJECT2_JSONTOKEN_HPP
