//
// Created by Raggdoll on 11/23/2019.
//

#include "numeralParser.hpp"
#include <stack>
Token *numeralParser::calculateRomanNumeral(std::vector<Token *> vector)
{
    std::cout << "Top CalculateRomanNumeral" << std::endl;
    int tempValue = 0;
    std::stack<int> s;
    for (unsigned int i = 0; i < vector.size(); i++)
    {
       while(vector[i]->isRomanNumber())
        {

               std::cout << "Before s.push" << std::endl;

               std::cout << " Here" << std::endl;
               s.push(romanNumeralToDecimal(vector[i]->romanNumber()));
               std::cout << "after s.push" << std::endl;
                 if(i+1 == vector.size()){
                     break;
                 }
                i++;
        }
        std::cout << "Before get Operand" << std::endl;
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
            s.pop();
            s.push(tempValue);
        }
        if (tempChar == '%')
        {
            tempValue = s.top();
            s.pop();
            tempValue %= s.top();
            s.pop();
            s.push(tempValue);
        }
    }
    std::cout << " Near the end" << std::endl;
    int outputDecimal = s.top();
    Token * returnToken = new Token();
         returnToken->romanNumber(decimalToRomanNumeral(outputDecimal));

    return returnToken;
}

int numeralParser::romanValue(char c)
{
    std::cout << "Top romanValue" << std::endl;
    std::cout << c << std::endl;
    switch (c)
    {
        case 'I': // code to be executed if n = 1;
             return 1;
        case 'V': // code to be executed if n = 2;
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
    std::cout << "Top romanNumeralToDecimal" << std::endl;
    std::cout << romanNumeral << std::endl;

    int Value = 0;
    for(unsigned int i = 0; i < romanNumeral.length(); i++){
        int s1 = romanValue(romanNumeral[i]);
        if(i + 1 < romanNumeral.length()){

            int s2 = romanValue(romanNumeral[i+1]);
            if(s1 >= s2){
                Value += s1;
            }else{
                Value += (s2 - s1);

            }
        }else{
            Value += s1;
        }
    }
std::cout << " Why you no go here" <<std::endl;
    std::cout << " Return value before return call" << std::endl;
    std::cout << Value << std::endl;
    return Value;
std::cout << " I should never get here" << std::endl;
}

char numeralParser::getOperand(Token *curToken)
{
    return curToken->getVariable();
}

std::string numeralParser::decimalToRomanNumeral(int decimal) // Leveraged from https://www.geeksforgeeks.org/converting-decimal-number-lying-between-1-to-3999-to-roman-numerals/
{
    std::cout << "Top decimalToRomanNumeral" << std::endl;
    std::cout << decimal << std::endl;
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
    std::cout << "Output" << std::endl;
    std::cout << output << std::endl;
    return output;
}
