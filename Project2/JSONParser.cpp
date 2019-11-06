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
        token.print();
        std::cout << "Terminating..." << std::endl;
        exit(1);
    }
    EntityInstance instance;
    do {
        Pair pair = parseAPair();
        instance.addAttribute(pair);
        token = tokenizer.getToken();
    } while( token.isComma() );  // after having read a pair, we expect a comma
    // So, we didn't find a comma. Then, it must be a close brace.
    if( ! token.isCloseBrace() ) {
        std::cout << "Error: JSONParser::parseJSONObject: Expected an close brace, but found" << std::endl;
        token.print();
        std::cout << "Terminating..." << std::endl;
        exit(1);
    }
    return instance;
}

Pair parseAPair(){

}