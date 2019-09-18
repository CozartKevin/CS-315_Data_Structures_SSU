//
// Created by Kevin Cozart on 8/31/2019.
//

#include "Tokenizer.hpp"
#include "Token.hpp"
#include "TagParser.hpp"

TagParser::TagParser(std::string fileName)
{
    Tokenizer tokenizer(fileName);  //Sends filename to Tokenizer for processinng
    Token token = tokenizer.getToken(); //sets first token to first Token from the Tokenizer.
    Token previousToken = token; //sets previousToken to first Token from the Tokenizer.
    token = tokenizer.getToken();// gets next token from Tokenizer.
    do
    {
// Start of main If/Else as referenced by other comments
        if (token.isOpenTag())
        {
            if (previousToken.isOpenTag()) // Handles double open tag case
            {
                stackToken.pop();
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
            handleCloseTag(token);
        }
        else if (token.isCloseStandAloneTag())
        {
            handleStandAloneTag(token);
        }
        else if (token.isCloseAngleBracket() || token.isOpenAngleBracket())
        {
            if (previousToken.isOpenTag())
            {
                if (token.isOpenAngleBracket())
                {
                    if (!stackToken.empty() && (previousToken.tagName() ==
                                                stackToken.top().tagName()))  //Checks to see if the bag Open tag is on the stack, and removes it if it is
                    {
                        stackToken.pop();
                    }
                    printError(
                            previousToken);  // Catches when previous tag is open tag but we have an open bracket right after.  Sends previous tag to error print and prints out the Open bracket error
                    token.print();
                    std::cout << (token.isCloseAngleBracket() ? " ignoring random close angle-bracket."
                                                              : " ignoring random open angle-bracket.") << std::endl;
                }
                else
                {
                    if (stackToken.empty()) //handles when previous token is Open and Token is closed angle bracket, thus confirming its a good tag. (only occurs due to priming of previousToken and token on first run. Pushes to the stack for processing)
                    {
                        stackToken.push(previousToken);
                    }
                }
            }
            else if (previousToken.isCloseTag() && token.isCloseAngleBracket() &&
                     !isInMap) //If the previous tag is a closed tag and token is a close angle bracket, but it didn't have a matching tag thus isInMap was set to false, sends to error message (No Open Tag Case)
            {
                errorStackToken.push(previousToken);
                printError(token);
                errorStackToken.pop();
            }
            else if (isInMap) // Sets isInMap to false after we have processed a good close tag that was pushed to the stack as a pair.
            {
                isInMap = false;
            }
            else
            {
                token.print(); // Error message catches random close or open brackets
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
    printWellFormedTagsFromMap(); //After entire file is processed this prints out the entire Map<string, pair<Token,Token>> tags
}


/*
 * handleOpenTag
 * Var In: Token && Private stackToken
 * Var Out: none
 * Pushes all potentially good open tags onto the stackToken for later processing main processing in main if/else
 *
 */
void TagParser::handleOpenTag(Token token)
{
    stackToken.push(token);
};


/*
 * handleCloseTag
 * Var In: Token && Private stackToken && Private errorStackToken
 * Var out: none
 * This section handles closed tags.  It verifies that there is anything on the stackToken
 *          If there is something on the stackToken it compares the Token tagname to the stackToken Top Tagname
 *          If there is NOT anything on the stackToken exit to process next token (catch for no open tag is in primary if/else)
 *                  If they match, send them to checkMapPushPairPopStack
 *                  If they DO NOT match, cycle through stackToken until there is a match.
 *                      If there is a match Send previous non match to errorStackToken, pop last value off of stackToken then print error message with errorStackToken and Token(Premature close case)
 *                      If they DO NOT match in stackToken then send error
 *                 if there is nothing in the errorStack set isInMap to false and check next token to verify if it is a good tag.
 *
 */
void TagParser::handleCloseTag(Token token)
{
    if (stackToken.size() > 0)
    {
        int cout = 0;
        if ((token.tagName() == (stackToken.top().tagName())))
        {
            checkMapPushPairPopStack(token);
        }
        else
        {
            bool badTag = false;
            if (!stackToken.empty() && stackToken.size() == 1)
            {

            }
            else
            {
                while (!stackToken.empty() && (token.tagName() != (stackToken.top().tagName())))
                {
                    errorStackToken.push(stackToken.top());
                    stackToken.pop();
                }
                if ((token.tagName() == (stackToken.top().tagName())))
                {
                    stackToken.pop();
                }
            }
            if (!errorStackToken.empty())
            {
                printError(token);
            }
            else
            {
                isInMap = false;
            }

        }
    }
    else
    {
    }
}

/*
 * checkMapPushPairPopStack
 * Var In: Token && Private stackToken stack
 * Var Out: none
 * checks with iterator to see if the current top stack value is in the map.
 * if it is in the map it submits the new pair to the map
 * if it is NOT in the map it creates a vector with name of the current tag and then pushes the pair into the map
 * removes the processed Open tag from the stack and sets flag to tell the main if/else that this token is in the map already
 * so that the main if/else can ignore printing any error messages on this token.
 *
*/
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
    isInMap = true;
    stackToken.pop();
};


/*
 * handleStandAloneTag
 * Var In: Token
 * Var Out: none
 * This handles all well formed br tags and will push them onto the stack using checkMapPushPairPopStack logic.
 */
void TagParser::handleStandAloneTag(Token token)
{
    if (stackToken.top().tagName() == "br" && token.tagName() == "/>")
    {
        checkMapPushPairPopStack(token);
    }
}


/*
 *
 * printWellFormedTagsFromMap
 * Var In: Private Map<String,Pair<Token,Token>> tags
 * Var Out: none
 * This will print all tags that were deemed good and pushed as a pair into the map.
 *
 */
void TagParser::printWellFormedTagsFromMap()
{
    std::cout << std::endl;
    std::cout << "The following is a list of well-formed HTML tags." << std::endl << std::endl;
    for (auto mapIter = tags.begin(); mapIter != tags.end(); ++mapIter)
    {
        std::cout << mapIter->first << " appeared in the following " << mapIter->second.size() << " locations."
                  << std::endl;

        std::vector<std::pair<Token, Token>> locations = mapIter->second;
        for (auto vIter = locations.begin(); vIter != locations.end(); ++vIter)
        {
            std::cout << "\t";
            vIter->first.print();
            std::cout << " -- ";
            vIter->second.print();
            std::cout << std::endl;
        }
        std::cout << std:: endl;
    }
}


/*
 * printError
 * Var In: Token && private errorStackToken stack
 * Var Out: none
 * This handles multiple error prints
 * Premature Close:
 * If there is a premature closing tag, it will have multiple entries on the error stack, then process those on to a vector for proper printing
 * it then removes those from the error stack and places them back on the stack to then be pop'd off the error stack
 * keep tags that were not closed during premature close for further processing
 *
 * Close Tag without Open Tag:
 * This will print out the previous token via errorStack and the Token bracket to reflect that there wasn't an Open tag that matches the closed tag
 *
 * Open Tag:
 * This will print out the error message for when an Open tag doesn't have the correct formatting in it.
 *
 *
 */
void TagParser::printError(Token token)
{
    if (errorStackToken.size() >= 2)
    {
        token.print();
        std::cout << " closes while the following tags remain open." << std::endl;
        std::vector<Token> v;
        Token t(1, 1);
        while (!errorStackToken.empty())
        {      // Reverses order of tags after premature closing tags and pops them back on the stack for further processing
            v.push_back(errorStackToken.top());
            stackToken.push(errorStackToken.top());
            errorStackToken.pop();
        }
        for (int i = v.size(); i > 0; i--)
        {   //Prints out good tags after premature closing tags.
            std::cout << "        ";
            t = v[i - 1];
            t.print();
            std::cout << std::endl;
        }
    }
    else if (token.isCloseTag() ||
             (!errorStackToken.empty() && errorStackToken.top().isCloseTag())) // Prints out non open tag closed tags
    {
        errorStackToken.top().print();
        std::cout << " (with close angle bracket ";
        token.print();
        std::cout << ") doesn't have a matching open tag.  Will discard it." << std::endl;

    }
    else if (token.isOpenTag()) //Prints out tags without proper closing
    {
        token.print();
        std::cout << " is missing a '>' or '/>'.  Will discard it." << std::endl;
    }

    return;
}



