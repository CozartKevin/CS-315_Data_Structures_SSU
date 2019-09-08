//
// Created by Ali A. Kooshesh on 8/21/18.
//

#ifndef LAB01_2_TOKEN_HPP
#define LAB01_2_TOKEN_HPP


#include <string>

class Token {
public:
    Token(int, int);
    bool &isOpenTag();
    bool &isCloseTag();

    bool &isCloseAngleBracket();
    bool &isOpenAngleBracket();
    bool &endOfFile();
    bool &isCloseStandAloneTag();

    std::string tagName();

    void makeOpenTag(std::string);
    void makeCloseTag(std::string);
    void makeStandAloneCloseTag(std::string name);
    void print();


private:
    bool _isOpenTag, _isCloseTag, _isCloseAngleBracket,_isOpenAngleBracket,
        _eof, _isCloseStandAloneTag;

    std::string _tagName;
    int _lineNumber, _charPos;

    void printLineandCharPos() const;


};


#endif //LAB01_2_TOKEN_HPP
