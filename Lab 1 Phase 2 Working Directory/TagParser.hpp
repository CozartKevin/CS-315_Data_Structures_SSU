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
#include <algorithm>


class TagParser {
public:

    TagParser(std::string fileName);
    void parsePrint();
    void handleOpenTag(Token token);
    void handleCloseTag(Token token);
    void handleStandAloneTag(Token token);
    void processForPrint();

private:
    std::map<std::string, std::vector<Token> > tags;
    std::map<std::string, std::vector<Token>>::iterator it;
};


#endif //LAB01_2_TAGPARSER_HPP
