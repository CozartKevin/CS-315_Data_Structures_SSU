//
// Created by Kevin on 11/4/2019.
//
#include <iostream>
#include "JSONToken.hpp"
#include "JSONParser.hpp"
#include "EntityInstance.hpp"
#include "Pair.hpp"
#include "Entity.hpp"


EntityInstance JSONParser::parseJSONObject() {
    // parseJSONObject is responsible for parsing a JSON object. As such,
    // the first token is expected to be an open brace.
    JSONToken token = tokenizer.getToken();
    if( ! token.isOpenBrace() ) {
        std::cout << "Error: JSONParser::parseJSONObject: Expected an open brace, but found" << std::endl;
        std::cout << "Terminating..." << std::endl;
        exit(1);
    }
    EntityInstance instance;
    do {
        Pair pair = parseAPair();
        instance.addAttribute(pair);
            token = tokenizer.getToken();
    } while( token.isComma());  // after having read a pair, we expect a comma
    if( ! token.isCloseBrace() ) {
        std::cout << "Error: JSONParser::parseJSONObject: Expected an close brace, but found" << std::endl;
        token.print();
        std::cout << "Terminating..." << std::endl;
        exit(1);
    }
    return instance;
}

Pair JSONParser::parseAPair(){
JSONToken token  = tokenizer.getToken();
JSONToken prevToken;

   while(!token.isComma()){
        if(token.isString()){

            if(prevToken.isString()){
                return Pair(prevToken.tagName(), token.tagName());
            }
            prevToken = token;
            token = tokenizer.getToken();
        }
        if(token.isColon()){
            token = tokenizer.getToken();
        }

        if(token.isNumber()){
           return Pair(prevToken.tagName(),token.toDouble());
        }
    }
   return Pair(prevToken.tagName(), token.tagName());
}

JSONParser::JSONParser(JSONTokenizer &tokenizer) : tokenizer(tokenizer)
{

}

Entity JSONParser::parseJSONEntity()
{

    JSONToken token = tokenizer.getToken();
    if( ! token.isOpenBracket() ) {
        std::cout << "Error: JSONParser::parseJSONObject: Expected an open bracket, but found" << std::endl;
        token.print();
        std::cout << "Terminating..." << std::endl;
        exit(1);
    }

    Entity entity;
    do {
        EntityInstance instance = parseJSONObject();
        entity.addObject(instance);


        token = tokenizer.getToken();
    } while( token.isComma());

    if( ! token.isCloseBracket() ) {
        std::cout << "Error: JSONParser::parseJSONObject: Expected an close bracket, but found" << std::endl;
        token.print();
        std::cout << "Terminating..." << std::endl;
        exit(1);
    }

    return entity;
}


