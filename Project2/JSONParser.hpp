//
// Created by Kevin on 11/4/2019.
//
#include "JSONTokenizer.hpp"
#include "Pair.hpp"
#include "EntityInstance.hpp"
#include "Entity.hpp"

#ifndef PROJECT2_JSONPARSER_HPP
#define PROJECT2_JSONPARSER_HPP

class JSONParser {
public:
    JSONParser(JSONTokenizer &tokenizer);



    Pair parseAPair();
    EntityInstance parseJSONObject();
    Entity parseJSONEntity();

private:
    JSONTokenizer &tokenizer;
};

#endif //PROJECT2_JSONPARSER_HPP
