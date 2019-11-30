//
// Created by Raggdoll on 11/23/2019.
//

#include "numeralParser.hpp"
#include <stack>
Token *numeralParser::calculateRomanNumeral(std::vector<Token *> vector)
{
    int tempValue = 0;
    std::stack<int> s;

    for (unsigned int i = 0; i < vector.size(); i++)
    {

       while(vector[i]->isRomanNumber())
        {
               s.push(romanNumeralToDecimal(vector[i]->romanNumber()));
                 if(i+1 == vector.size()){
                     break;
                 }
                i++;
        }

        char tempChar = getOperand(vector[i]);

        if (tempChar == '+')
        {
            tempValue = s.top();
            s.pop();
            tempValue += s.top();
            s.pop();
            s.push(tempValue);
        }
        if (tempChar == '-')
        {
            tempValue = s.top();
            s.pop();
            tempValue = s.top() - tempValue;
            s.pop();
            s.push(tempValue);
        }
        if (tempChar == '*')
        {
            tempValue = s.top();
            s.pop();
            tempValue *= s.top();
            s.pop();
            s.push(tempValue);
        }
        if (tempChar == '/')
        {
            tempValue = s.top();
            s.pop();
            tempValue = s.top() / tempValue;
            std::cout << tempValue << " -------------------------------------------------------- AFTER divide OPERATION " << std::endl;
            s.pop();
            s.push(tempValue);
        }
        if (tempChar == '%')
        {
            tempValue = s.top();
            s.pop();
            tempValue = s.top() %= tempValue;
            std::cout << tempValue << " -------------------------------------------------------- AFTER MOD OPERATION " << std::endl;
            s.pop();
            s.push(tempValue);
        }
    }

    int outputDecimal = s.top();

    Token * returnToken = new Token();
         returnToken->romanNumber(decimalToRomanNumeral(outputDecimal));

    return returnToken;
}

int numeralParser::romanValue(char c)
{
    switch (c)
    {
        case 'I':
             return 1;
        case 'V':
            return 5;
        case 'X':
            return 10;
        case 'L':
            return 50;
        case 'C':
            return 100;
        case 'D':
            return 500;
        case 'M':
            return 1000;
        default:
            return 0;
    }
}

int numeralParser::romanNumeralToDecimal(std::string romanNumeral)
{
    int total = 0;

    for(unsigned int i = 0; i < romanNumeral.length();i++){
        if(i + 1 < romanNumeral.length()){
            if(romanValue(romanNumeral[i]) >= romanValue(romanNumeral[i +1])){
                total += romanValue(romanNumeral[i]);
            }else{
                total -= romanValue(romanNumeral[i]);
            }
        }else{
            total += romanValue(romanNumeral[i]);
        }
    }

return total;
}

char numeralParser::getOperand(Token *curToken)
{
    return curToken->getVariable();
}

std::string numeralParser::decimalToRomanNumeral(int decimal) // Leveraged from https://www.geeksforgeeks.org/converting-decimal-number-lying-between-1-to-3999-to-roman-numerals/
{
    std::string output ="";
    int num[] = {1,4,5,9,10,40,50,90,100,400,500,900,1000};
    std::string sym[] = {"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"};
    int i=12;

    while(decimal>0)
    {
        int div = decimal/num[i];
        decimal = decimal%num[i];
        while(div--)
        {
            output += sym[i];
        }
        i--;
    }

    return output;
}
