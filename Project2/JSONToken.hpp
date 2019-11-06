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
    bool &isComma();
    bool &endOfFile();
    bool &isDouble();

    void makeOpenBrace(std::string name);
    void makeCloseBrace(std::string name);
    void makeComma(std::string name);
    void makeOpenBracket(std::string name);
    void makeCloseBracket(std::string name);
    void makeDouble(std::string name);


    std::string tagName();

    void makeTag(std::string);
    void makeTag(char);
    void print();

private:
    bool _isOpenTag, _isCloseTag,_isOpenBracket, _isCloseBracket, _isCloseBrace, _isOpenBrace,_isComma, _isDouble,
            _eof ;

    std::string _tagName;

};




#endif //PROJECT2_JSONTOKEN_HPP
