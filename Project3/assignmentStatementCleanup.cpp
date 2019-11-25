//
// Created by Raggdoll on 11/24/2019.
//

#include "assignmentStatementCleanup.hpp"

void assignmentStatementCleanup::setVariable(std::vector<Token *> &tokens, std::vector<Token *> &outputVector)
{


    if(tokens.front()->isAVariable()){
        do{
            if(!tokens.front()->isEqualSign())
            {
                outputVector.push_back(tokens.front());
            }
            tokens.erase(tokens.begin());
        }while(tokens.front()->isEqualSign());
    }
/*
    for( auto token : outputVector  ) // outputs the output vector after removing variable and equal sign
        token->print();
    std::cout << std::endl;

    for( auto token : tokens ) // outputs the token vector after removing variable and equal sign
        token->print();
    std::cout << std::endl;
8*/
std::cout << " Before second variable search" << std::endl;
    for(unsigned int i = 0; i < tokens.size(); i++){
       // tokens[i]->print();
      //  std::cout << tokens[i]->getVariable() << std::endl;
       // std::cout << std::endl;

            if(tokens[i]->isAVariable()){
                tokens[i]->print();
                std::cout << " is a variable" << std::endl;
                int j = 0;
               for(unsigned int j = 0; j < outputVector.size(); j++)
                std::cout << outputVector[j]->getVariable() << std::endl;
                std::cout << " is an OUTPUT VECTOR variable" << std::endl;
                if(tokens[i]->getVariable() == outputVector[j]->getVariable()){
                    std::cout << " inside match" << std::endl;
                    tokens[i] = new Token(outputVector[j]->romanNumber());
                    std::cout << tokens[i]->romanNumber() << std::endl;
                }else{

            }
        }
    }
}
