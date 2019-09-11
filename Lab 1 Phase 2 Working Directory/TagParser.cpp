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
    Token previousToken = token;
    token = tokenizer.getToken();
    do
    {

        if (token.isOpenTag())
        {
            if (previousToken.isOpenTag())
            {
             // std::cout << " This error Message Call" << std::endl;
                printError(previousToken);
                handleOpenTag(token);
            }
            else
            {
                handleOpenTag(token);
            }
        }
        else if (token.isCloseTag())
        {
            errorStackToken.push(previousToken);
                handleCloseTag(token);
                //std::cout << " Pop 1" << std::endl;
                if(!errorStackToken.empty())
                {
                    errorStackToken.pop();
                }

        }
        else if (token.isCloseStandAloneTag())
        {
            handleStandAloneTag(token);
        }
        else if (token.isCloseAngleBracket() || token.isOpenAngleBracket())
        {
            /*if(!stackToken.empty()){
                stackToken.top().print();
            }*/

            if (previousToken.isOpenTag())
            {
                if(stackToken.empty())
                {
                    stackToken.push(previousToken);
                }else { errorStackToken.push(token);
                printError(token);
               //     std::cout << " Pop 2" << std::endl;
                errorStackToken.pop();
                }
            }
            else if (previousToken.isCloseTag() && token.isCloseAngleBracket())
            {
             //   std::cout << " This error Message Call" << std::endl;
                if (stackToken.empty()){
                 //   std::cout << errorStackToken.size() << "Error stack size before message " << std::endl;
                    errorStackToken.push(token);
                  //  std::cout << errorStackToken.size() << "after Push stack size before message " << std::endl;
                  //  std::cout << previousToken.tagName() + " <- Previous tagname : token tagname -> ";
                  //  token.print();
                    printError(previousToken);
                   // std::cout << " Pop 3" << std::endl;
                   errorStackToken.pop();
               //
               }else
                {



                    //if((stackToken.empty()) && (previousToken.tagName() == stackToken.top().tagName())){
                    //  std::cout << " Inside Prious al;skdjf asdf asdf " << std::endl;
                    //}else{

                }

            }
            else
            {
                token.print();
                std::cout << (token.isCloseAngleBracket() ? " ignoring random close angle-bracket."
                                                          : " ignoring random open angle-bracket.") << std::endl;
            }
        }
        else
        {
            token.print();
            std::cout << " unknown token." << std::endl;
        }
        previousToken = token;
        token = tokenizer.getToken();


    } while (!token.endOfFile());
    printWellFormedTagsFromMap();
}

void TagParser::handleOpenTag(Token token)
{
    //Push to stack for later verification
//std::cout << token.tagName() << " Tag Name before pushing to stack" << std::endl;


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
    if (stackToken.size() > 0)
    {

        //std::cout << stackToken.top().tagName() + " Stack Name " + token.tagName() + " Token Tag name  inside handle close tag" << std::endl;
        if (token.tagName() == ("/" + stackToken.top().tagName()))
        {
            //  pairedTags = std::make_pair(stackToken.top(),token);
            //pairedTagsInVector.push_back(pairedTags);
           // std::cout << "Inside if for Token tagname and stack tagname" << std::endl;
            checkMapPushPairPopStack(token);

        }
        else
        {
            int count = 0;
            bool badTag = false;
         //  std::cout << "Inside else for Token tagname and stack tagname" << std::endl;
            while(token.tagName() != ("/" + stackToken.top().tagName()))
            {
              //  std::cout << " Inside while for compare empty token call" << std::endl;

                if(!stackToken.empty())
                {
                    errorStackToken.push(stackToken.top());
                   // std::cout << " Pop 4" << std::endl;
                    stackToken.pop();
                }
                count++;
                if(stackToken.empty()){
                    while(!errorStackToken.empty()){
                        stackToken.push(errorStackToken.top());
                       // std::cout << " Pop 5" << std::endl;
                            errorStackToken.pop();

                      //  std::cout << " Inside while for stack to error" << std::endl;
                    }
                    badTag = true;
                  // std::cout << " Inside stack empty token call" << std::endl;

                }
                if(badTag){
                    break;
                }
            }
           // token.print();
            //std::cout << " Error  " << std::endl;
           // errorStackToken.push(token);
       //     printError(token);
         //   std::cout << " Pop 6" << std::endl;
         //   errorStackToken.pop();

        }
    }
   else
    {
      // std::cout << " Inside Close Tag Hand send to error " << std::endl;
     //  std::cout << " This error Message Call Close Tag handler" << std::endl;

     // printError(token);
     // std::cout << " after error call in Clos Tag Hand" << std::endl;
      //  return;
    }
//if they don't match report error message.



}

void TagParser::checkMapPushPairPopStack(Token &token)
{
    it = tags.find(stackToken.top().tagName());

    if (it != tags.end())
    {
      //  std::cout << " Inside Iterator IF" << std::endl;
        tags[stackToken.top().tagName()].push_back(std::make_pair(stackToken.top(), token));
    }
    else
    {
       // std::cout << " Outside Iterator IF" << std::endl;
        tags[stackToken.top().tagName()] = std::vector<std::pair<Token, Token>>();
        tags[stackToken.top().tagName()].push_back(std::make_pair(stackToken.top(), token));
    }
   // stackToken.top().print();
    //std::cout << " Pop 7" << std::endl;
    stackToken.pop();
   /*
    if(!stackToken.empty()){
        stackToken.top().print();
    }*/
};

void TagParser::handleStandAloneTag(Token token)
{

    if (stackToken.top().tagName() == "br" && token.tagName() == "/>")
    {
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

void TagParser::printError(Token token)
{

        if(errorStackToken.size() >= 2){
            token.print();
            std::cout << " closes while the following tags remain open." << std::endl;
            while(!errorStackToken.empty()){
                std::cout << '/t';
                errorStackToken.top().print();
                stackToken.push(errorStackToken.top());
              //  std::cout << " Pop 8" << std::endl;
                errorStackToken.pop();
            }
        }else if (token.isCloseTag())
        {
           // errorStackToken.top().print();

           // std::cout << errorStackToken.size() + "<- error stack size : error stack name value -> ";
           // errorStackToken.top().print();

            token.print();
            std::cout << "(with close angle bracket ";
            errorStackToken.top().print();

            std::cout << " doesn't have a matching open tag.  Will discard it." << std::endl;

        }
        else if (token.isOpenTag())
        {
            token.print();
            std::cout << " is missing a '>' or '/>'.  Will discard it." << std::endl;
        }

    return;
}




// more things to do here...