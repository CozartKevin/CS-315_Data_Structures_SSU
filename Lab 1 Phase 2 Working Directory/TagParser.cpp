//
// Created by Kevin Cozart on 8/31/2019.
//

#include "Tokenizer.hpp"
#include "Token.hpp"
#include "TagParser.hpp"
TagParser::TagParser(std::string fileName)
{

    Tokenizer tokenizer(fileName);

    Token token = tokenizer.getToken();


    do
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
         //   token.print();
          //  std::cout << (token.isCloseAngleBracket() ? " ignoring random close angle-bracket."
           //                                     : " ignoring random open angle-bracket.") << std::endl;
        }
        else
        {
            token.print();
            std::cout << " unknown token." << std::endl;
        }

        token = tokenizer.getToken();


    } while (!token.endOfFile());
    printWellFormedTagsFromMap();
}

void TagParser::handleOpenTag(Token token)
{
    //Push to stack for later verification
std::cout << token.tagName() << " Tag Name before pusing to stack" << std::endl;
    stackToken.push(token);
    // tags[token.tagName()].push_back(token);
/*
    it = tags.find(token.tagName());
    if (it != tags.end())
    {

return;


    }
    else
    {
       return;
    }
*/

};

void TagParser::handleCloseTag(Token token)
{
//std::cout << "handleCloseTag     </       " << std::endl;
    //  std::cout << stackToken.top().tagName() + " Stack tag name in handleClosedTag" << std::endl;
    //  std::cout << "/" + stackToken.top().tagName() + " Stack Tag name with / in it in handlCLosedTag" << std::endl;
    //  std::cout << token.tagName() + " Token tag name in handleClosedTag" << std::endl;
//setup to compare close tag with top value of stack  : tagname
//if top value tagnames match: Push to pairedTag vector
if( stackToken.size() > 0)
{
    if (token.tagName() == ("/" + stackToken.top().tagName()))
    {
        //  pairedTags = std::make_pair(stackToken.top(),token);
        //pairedTagsInVector.push_back(pairedTags);

        checkMapPushPairPopStack(token);

    }
    else
    {
        printError(token);
        stackToken.pop();
    }
}else{
    printError(token);
    return;
}
//if they don't match report error message.



}

void TagParser::checkMapPushPairPopStack(Token &token)
{
    it = tags.find(stackToken.top().tagName());

    if (it != tags.end())
    {
        tags[stackToken.top().tagName()].push_back(std::make_pair(stackToken.top(), token));
    }
    else
    {
        tags[stackToken.top().tagName()] = std::vector<std::pair<Token, Token>>();
        tags[stackToken.top().tagName()].push_back(std::make_pair(stackToken.top(), token));
    }

    stackToken.pop();
};

void TagParser::handleStandAloneTag(Token token)
{

    if(stackToken.top().tagName() == "br" && token.tagName() == "/>"){
        checkMapPushPairPopStack(token);
    }
}

void TagParser::printWellFormedTagsFromMap()
{


    std::cout << "The following is a list of well-formed HTML tags." << std::endl << std::endl;


    for (auto mapIter = tags.begin(); mapIter != tags.end(); ++mapIter)
    {
        std::cout << mapIter->first << " appeared in the following " << mapIter->second.size() << " locations."
                  << std::endl;

        // our map, pairs an array of Tokens with tag-name strings.
        std::vector<std::pair<Token, Token>> locations = mapIter->second;
        for (auto vIter = locations.begin(); vIter != locations.end(); ++vIter)
        {
            std::cout << "\t";
            vIter->first.print();
            std::cout << " -- ";
            vIter->second.print();

            std::cout << std::endl;
        }

    }


}
void TagParser::printError(Token token){
    if(token.isCloseTag())
    {
        token.print();
        std::cout << "(with close angle bracket ";

        std::cout << " doesn't have a matching open tag.  Will discard it." << std::endl;
    }else if(token.isOpenTag()){
        std::cout << token.tagName() <<  " is missing a '>' or '/>'.  Will discard it." << std::endl;
    }
    return;
}




// more things to do here...