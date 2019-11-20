#include "Token.hpp"

void Token::print() const {
    if( eol() ) std::cout << "EOL" ;
    else if( eof()                      )  std::cout << "EOF" ;
    else if( isOpenParen()              )  std::cout << "(" ;
    else if( isCloseParen()            )  std::cout << ")" ;
    else if( isEqualSign()              )  std::cout << " = " ;
    else if( isMultiplicationOperator() )  std::cout << " * " ;
    else if( isAdditionOperator()       )  std::cout << " + " ;
    else if( isSubtractionOperator()    )  std::cout << " - " ;
    else if( isModuloOperator()         )  std::cout << " % " ;
    else if( isDivisionOperator()       )  std::cout << " % " ;
    else if( isRomanNumber()            )  std::cout << " " << romanNumber() << " ";
    else if( isAVariable()              )  std::cout << " " << getVariable() << " ";
}

void Token::init() {
    _romanNumber = "";
    _eof = _eol = false; 
    _symbol = '\0';
}
