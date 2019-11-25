//
// Created by Raggdoll on 11/23/2019.
//

#ifndef PROJECT1_NUMERALPARSER_HPP
#define PROJECT1_NUMERALPARSER_HPP
#include "Token.hpp"
#include <vector>

class numeralParser {
public:
    static Token *calculateRomanNumeral(std::vector<Token *> vector);
    static int romanValue(char c);
    static int romanNumeralToDecimal(std::string romanNumeral);
    static std::string decimalToRomanNumeral(int decimal);
    static char getOperand(Token * curToken);

};


#endif //PROJECT1_NUMERALPARSER_HPP
