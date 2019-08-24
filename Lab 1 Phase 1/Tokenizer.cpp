//
// Created by Ali A. Kooshesh on 8/21/18.
// Leveraged then Modified to Fullfil Lab 1 Phase 1
// By Kevin J. Cozart
//

#include <iostream>
#include "Tokenizer.hpp"

Tokenizer::Tokenizer(std::string name) : lineNumber{1},
                                         charPosition{1},
                                         inputFileName{name}
{
    inputStream.open(inputFileName,
                     std::ios::in);  // open the input file. We will make sure that it is open in getToken.
}

bool Tokenizer::charOfInterest(char c)
{
    // is c the initial (or the sole) character of a token?
    if (c == '<')
    {
        return true;
    }
    else if (c == '>')
        {
            return true;
        }
        else
        {
            return false;
        }

    // return true;    you need to replace this with code that compares c with characters like '<', '>', etc.
}

Token Tokenizer::getToken()
{
    char c;

    if (!inputStream.is_open())
    {
        std::cout << "Tokenizer::getToken() called with a stream that is not open." << std::endl;
        std::cout << "Make sure that " << inputFileName << " exists and is readable. Terminating.";
        exit(2);
    }

    while (inputStream.get(c) && !charOfInterest(c))
    {
        // keep track of the line number and the character position
        if (c == '\n')
        {
            lineNumber++;
            charPosition = 1;
        }
        else
        {
            charPosition++;
        }
    }

    Token token(lineNumber, charPosition);
    token.endOfFile() = false;
    if (inputStream.eof())
    {
        token.endOfFile() = true;
        return token;
    }
    if (c == '<')
    {   // A possible open tag.
        // suppose we have found an open em-tag.
        //parse remaining variables within the tag until the >
        //Then make token.makeOpenTag with full variable until >
        //setup a stream into a string variable until we reach a >
        std::string tagName;
        do
        {
            inputStream.get(c);
            tagName = tagName + c;

        } while (inputStream.peek() != '>');

        token.makeOpenTag(tagName);
        charPosition += tagName.length() + 1;
        return token;
    }
    else
    {
        if (c == '>')
        {


            token.isCloseAngleBracket() = true;
            charPosition++;
            return token;
        }
        else
        {

        }
    }
}// ... more if-else statements here.


