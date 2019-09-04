//
// Created by Kevin Cozart on 8/31/2019.
//

#include "Tokenizer.hpp"
#include "TagParser.hpp"
#include "Token.hpp"

TagParser::TagParser(std::string fileName)
{
 //   std::cout << "inside TagParser" << std::endl;
//setup traversable stack



    Tokenizer tokenizer(fileName);

    Token token = tokenizer.getToken();

    while (!token.endOfFile())
    {


        if (token.isOpenTag())
        {
            handleOpenTag(token);
        }
        else if (token.isCloseTag())
        {
            handleCloseTag(token);
        }
        else if (token.isCloseStandAloneTag())
        {
            handleStandAloneTag(token);
        }
        else if (token.isCloseAngleBracket() || token.isOpenAngleBracket())
        {
           // token.print();
          //  std::cout << (token.isCloseAngleBracket() ? " ignoring random close angle-bracket."
                //                                      : " ignoring random open angle-bracket.") << std::endl;
        }
        else
        {
            token.print();
            std::cout << " unknown token." << std::endl;
        }

        token = tokenizer.getToken();


}
    processForPrint();
}

void TagParser::handleOpenTag(Token token)
{

    tags[token.tagName()].push_back(token);
    /*
    it = tags.find(token.tagName());
    if (it != tags.end())
    {
        tags[token.tagName()] = std::vector<Token>();

        tags[token.tagName()].push_back(token);
    }
    else
    {
        tags[token.tagName()].push_back(token);
    }
*/

};

void TagParser::handleCloseTag(Token token)
{
std::cout << "handleCloseTag     </       " << std::endl;

};

void TagParser::handleStandAloneTag(Token token)
{
    std::cout << "Stand Alone Tag            />     " << std::endl;
}

void TagParser::processForPrint()
{
    std::cout << "The following is a list of well-formed HTML tags." << std::endl;

    for (auto mapIter = tags.begin(); mapIter != tags.end(); ++mapIter)
    {
        // our map, pairs an array of Tokens with tag-name strings.
        std::vector<Token> locations = mapIter->second;
        for (std::vector<Token>::iterator vIter = locations.begin(); vIter != locations.end(); ++vIter)
        {
            vIter->print();
            std::cout << std::endl;
        }
    }

}

void TagParser::parsePrint()
{

std::cout << "Inside Tag Parce Print"  << std::endl;

    return;
}


// more things to do here...