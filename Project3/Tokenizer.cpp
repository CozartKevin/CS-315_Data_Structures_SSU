//
// Created by Raggdoll on 11/29/2019.
//
#include <iostream>
#include <utility>
#include "Tokenizer.hpp"

Tokenizer::Tokenizer(std::string s)
{
    toProcessString = std::move(s);  // open the input file. We will make sure that it is open in getToken.
}

void Tokenizer::buildVector(std::vector<Token *> &tokens)
{
    std::string tagName;
    char c = 0;

    for (unsigned int i = 0; i < toProcessString.length(); i++)
    {
        c = toProcessString[i];
        if (c != ' ')
        {
            while (toProcessString[i] == 'I' || toProcessString[i] == 'V' || toProcessString[i] == 'X' ||
                   toProcessString[i] == 'L' || toProcessString[i] == 'C' || toProcessString[i] == 'D' ||
                   toProcessString[i] == 'M')
            {
                tagName += c;
                i++;
                c = toProcessString[i];

            }

            if (tagName == "I" || tagName == "V" || tagName == "X" || tagName == "L" || tagName == "C" ||
                tagName == "D" ||
                tagName == "M" || (tagName.length() > 1))
            {
                auto *token = new Token();
                token->romanNumber(tagName);
                tokens.push_back(token);
                tagName = "";
            }
            if (c == '+' || c == '*' || c == '-' || c == '/' || c == '%' || c == '(' || c == ')' || c == '=' ||
                (c >= 'a' && c <= 'z'))
            {
                tokens.push_back(new Token(c));
            }
        }
    }

    auto *token = new Token();
    token->eol(true);
    tokens.push_back(token);
    tagName = "";
}


void Tokenizer::setVariable(std::vector<Token *> &tokens, std::vector<Token *> &outputVector)
{

    if (tokens.front()->isAVariable())
    {
        do
        {
            if (!tokens.front()->isEqualSign())
            {
                outputVector.push_back(tokens.front());
            }
            tokens.erase(tokens.begin());
        } while (tokens.front()->isEqualSign());
    }


    for (unsigned int i = 0; i < tokens.size(); i++)
    {
        if (tokens[i]->isAVariable())
        {

            for (unsigned int j = 0; j < outputVector.size(); j++)
            {
                if (tokens[i]->getVariable() == outputVector[j]->getVariable())
                {
                    tokens[i] = new Token(outputVector[j]->romanNumber());
                }
            }
        }
    }
}
