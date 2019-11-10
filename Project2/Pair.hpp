//
// Created by Kevin on 11/5/2019.
//

#ifndef PROJECT2_PAIR_HPP
#define PROJECT2_PAIR_HPP
#include <string>
#include "JSONToken.hpp"

class Pair { // represents a single attribute and its value:

public:
    Pair();
    Pair(std::string attributeName, std::string attributeValue);
    Pair(std::string attributeName, double doubleValue);
    bool isDouble();  // is the datatype of the value of this attribute a double?
    double numberValue();
    std::string stringValue();
    std::string attributeName();
    void print();

private:
    std::string _attributeName, _attributeStringValue;
    double _attributeNumberValue;
    bool _isNumber;
};

#endif //PROJECT2_PAIR_HPP
