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
  //  std::cout << " Top of Parse JSON" << std::endl;
    if( ! token.isOpenBrace() ) {
        std::cout << "Error: JSONParser::parseJSONObject: Expected an open brace, but found" << std::endl;
       // token.print();
        std::cout << "Terminating..." << std::endl;
        exit(1);
    }
    EntityInstance instance;
    do {
        Pair pair = parseAPair();
        // pair.print();

        instance.addAttribute(pair);
       // std::cout << " Here" << std::endl;
        //token.print();
            token = tokenizer.getToken();
//token.print();
    } while( token.isComma());  // after having read a pair, we expect a comma
    // So, we didn't find a comma. Then, it must be a close brace.
      //  instance.print();
    if( ! token.isCloseBrace() ) {
        std::cout << "Error: JSONParser::parseJSONObject: Expected an close brace, but found" << std::endl;
        token.print();
        std::cout << "Terminating..." << std::endl;
       // std::cout << " I AM HERE FOR NOW" << std::endl;
        exit(1);
    }
    return instance;
}

Pair JSONParser::parseAPair(){
 //   std::cout << " TOP  parse A PAIR " << std::endl;
JSONToken token  = tokenizer.getToken();
JSONToken prevToken;



   while(!token.isComma()){
      // token.print();
       //prevToken.print();
        if(token.isString()){

            if(prevToken.isString()){
               // prevToken.print();
              //  token.print();
               // std::cout << "Parse a Pair before returning Pair for two strings" << std::endl;
                return Pair(prevToken.tagName(), token.tagName());
            }
            prevToken = token;
            token = tokenizer.getToken();
        }
        if(token.isColon()){
            token = tokenizer.getToken();
        }

        if(token.isNumber()){
           // prevToken.print();
            //token.print();
           // std::cout << "Parse a Pair before returning Pair for string and double" << std::endl;
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
//std::cout << " Top Parse Entity" << std::endl;
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
      //  std::cout << " I am HERE" << std::endl;
       // instance.print();
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


