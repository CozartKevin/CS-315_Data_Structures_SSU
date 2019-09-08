//
// Created by Raggdoll on 8/31/2019.
//

#ifndef LAB01_2_TAGPARSER_HPP
#define LAB01_2_TAGPARSER_HPP
#include <iostream>
#include <string>
#include<map>
#include<vector>
#include<iterator>
#include<stack>
#include <algorithm>


class TagParser {
public:

    TagParser::TagParser(std::string fileName);


private:

    std::map<std::string, std::vector<std::pair<Token,Token>>> tagErrors;
    std::map<std::string, std::vector<std::pair<Token,Token>>> tags;
    std::map<std::string, std::vector<std::pair<Token,Token>>>::iterator it;
    std::stack<Token> stackToken;
    std::stack<Token> errorStackToken;

    void checkMapPushPairPopStack(Token &token);


    void handleOpenTag(Token token);
    void handleCloseTag(Token token);
    void handleStandAloneTag(Token token);
    void printWellFormedTagsFromMap();
    void printError(Token token);

};


#endif //LAB01_2_TAGPARSER_HPP
