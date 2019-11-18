//
// Created by Raggdoll on 11/3/2019.
//
#include <iostream>
#include <fstream>
#include "JSONTokenizer.hpp"
 JSONTokenizer::JSONTokenizer(std::string name) :
                                         inputFileName{name}
{
    inputStream.open(inputFileName,
                     std::ios::in);  // open the input file. We will make sure that it is open in getToken.
}


bool JSONTokenizer::charOfInterest(char c)
{
    // is c the initial (or the sole) character of a token?
    if (c == '[' || c == ']' || c == '{' || c == '}' || c == ':' || c == ',' || c == '"')
    {
        return true;
    }else if(isdigit(c)){
        return true;
    }
    else
    {
        return false;
    }
}
JSONToken JSONTokenizer::getToken()
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

    }

    JSONToken jsontoken;
    if (inputStream.eof())
    {
        jsontoken.endOfFile() = true;
        return jsontoken;
    }

//Verify that you can still parse the file propery..
    if (c == '[' ){
        jsontoken.makeOpenBracket("[");
        return jsontoken;
}else if(c == ']' ){
        jsontoken.makeCloseBracket("]");
        return jsontoken;
    }else if( c == '{' ){
        jsontoken.makeOpenBrace("{");
        return jsontoken;
    }else if( c == '}' ){
        jsontoken.makeCloseBrace("}");
        return jsontoken;
    }else if(c == ',')
    {
        jsontoken.makeComma(",");
        return jsontoken;
    }else if(c == ':'){
                 jsontoken.makeColon(":");
            return jsontoken;

    }else if(isdigit(c)){
        inputStream.putback(c);
        std::string tagName;
        tagName = getString(c, tagName, inputStream);
        jsontoken.makeNumber(tagName);
        return jsontoken;


    }else if(c == '"')
    {

        std::string tagName;
        tagName = getString(c, tagName, inputStream);
        jsontoken.makeString(tagName);
        if(inputStream.peek() == '"') {
            inputStream.get(c);
        }
        return jsontoken;
    }

std::cout <<  " End of get Token,  call ran away" << std::endl;
}



std::string &JSONTokenizer::getString(char c, std::string &tagName, std::istream &inputStream) const
{

    do
    {
        inputStream.get(c);
        tagName = tagName + c;
    } while (inputStream.peek() != '"' && inputStream.peek() != ',' && inputStream.peek() != '}' && !inputStream.eof());

    return tagName;
}
