//
// Created by Raggdoll on 11/29/2019.
//
#include <iostream>
#include <fstream>
#include <string>
#include "Tokenizer.hpp"

Tokenizer::Tokenizer(std::string s)
{
    toProcessString = s;  // open the input file. We will make sure that it is open in getToken.
}

/*
std::string Tokenizer::parseTagName(char c, std::string tagName, std::istream &inputStream) const
{
    //  std::cout << " Top Parse Tag Name " << std::endl;

    return tagName;
}

Token *Tokenizer::getTokenName()
{
    char c;


    std::cout << " Top Get Token Name" << std::endl;
    Token *token = new Token();
    std::string tagName = "";
    tagName = parseTagName(c, tagName, inputStream);
    std::cout << tagName.length() << " TagName length " << std::endl;
    std::cout << tagName << "                                        Tag Name" << std::endl;


    return token;
}

bool Tokenizer::charOfInterest(char c)
{
    // is c the initial (or the sole) character of a token?
    if (c == '+' || c == '*' || c == '-' || c == '/' || c == '%' || c == '(' || c == ')' || c == '=')
    {
        return true;
    }else if(isalpha(c)){
        return true;
    }
    else
    {
        return false;
    }
}
*/
void Tokenizer::buildVector(std::vector<Token *> &tokens)
{
    std::string tagName = "";
    char c = 0;

    for (unsigned int i = 0; i < toProcessString.length(); i++)
    {
        c = toProcessString[i];
     //   std::cout << c << " is c from inputstream" << std::endl;
        if (c != ' ')
        {
            while (toProcessString[i] == 'I' || toProcessString[i] == 'V' || toProcessString[i] == 'X' ||
                   toProcessString[i] == 'L' || toProcessString[i] == 'C' || toProcessString[i] == 'D' ||
                   toProcessString[i] == 'M')
            {
                tagName = tagName + c;
            //    std::cout << tagName << " Is tagname in ELSE" << std::endl;
            //    std::cout << tagName.length() << " is tagname length in ELSE" << std::endl;
                i++;
                c = toProcessString[i];
           //     std::cout << tagName << " Tag Name in loop" << std::endl;
            }
            // std::cout << " Inside dowhile for parse tag name " << std::endl;

         //   std::cout << tagName << "                                                 Tag Name in else" << std::endl;
          //  std::cout << " else of processess" << std::endl;
            if (tagName == "I" || tagName == "V" || tagName == "X" || tagName == "L" || tagName == "C" ||
                tagName == "D" ||
                tagName == "M" || (tagName.length() > 1))
            {
                Token *token = new Token();
                token->romanNumber(tagName);
                tokens.push_back(token);
                tagName = "";
            }
            if (c == '+' || c == '*' || c == '-' || c == '/' || c == '%' || c == '(' || c == ')' || c == '=' ||
                (c >= 'a' && c <= 'z'))
            {
               std::cout << " Symbol tokens are ";
                std::cout << c << std::endl;
                tokens.push_back(new Token(c));
            }
        }
    }

    Token *token = new Token();
    token->eol(true);
    tokens.push_back(token);
    tagName = "";
}