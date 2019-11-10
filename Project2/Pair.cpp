//
// Created by Kevin on 11/5/2019.
//
#include <iostream>
#include "Pair.hpp"
Pair::Pair(){
    _attributeName = "";
    _attributeStringValue = "";
    _attributeNumberValue = 0.0f;
    _isNumber = false;
}
Pair::Pair(std::string attributeName, std::string attributeValue)
{
    _attributeName = attributeName;
    _attributeStringValue = attributeValue;
    _isNumber = false;
}

Pair::Pair(std::string attributeName, double value)
{

    _attributeName = attributeName;
    _attributeNumberValue = value;
    _isNumber = true;
}

bool Pair::isDouble(){
   return _isNumber;
}

double Pair::numberValue()
{
    return _attributeNumberValue;
}

std::string Pair::stringValue(){
    return _attributeStringValue;
}

std::string Pair::attributeName()
{
    return _attributeName;
}

void Pair::print(){

    if(isDouble()){
        std::cout << '"' <<  attributeName() << '"' << ": " << numberValue();
    }else
    {
        std::cout << '"' << attributeName() << '"' << ": " << '"' << stringValue() << '"';
    }
}