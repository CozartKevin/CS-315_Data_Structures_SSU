//
// Created by Kevin on 11/5/2019.
//
#include <iostream>
#include "EntityInstance.hpp"
EntityInstance::EntityInstance(): numberOfAttributes{0}{
}
void EntityInstance::addAttribute(Pair &insertedPair){
    numberOfAttributes++;
    //entityAttributeNames.push_back(insertedPair.attributeName());
    entityAttributes.push_back(insertedPair);

}

int EntityInstance::numAttributes(){
    return numberOfAttributes;
}
/*
std::vector<std::string> & EntityInstance::attributeNames(){

return;
}
*/

void EntityInstance::print(){
    std::cout << "{" << std::endl;
    for(unsigned int i = 0; i < entityAttributes.size();i++){
      // std::cout << '\n';
       entityAttributes[i].print();
        if(i+1 < entityAttributes.size()){
            std::cout << "," << std::endl;
        }else{
            std::cout <<  std::endl << "}" << std::endl;
        }
    }
}

std::string EntityInstance::getPairID()
{
    for(unsigned int i = 0; i < entityAttributes.size(); i++){
        if(  entityAttributes[i].attributeName()  == "id")
        {
            return entityAttributes[i].stringValue();
        }
    }
}

std::string EntityInstance::getPairTerm()
{
    for(unsigned int i = 0; i < entityAttributes.size(); i++){
        if(  entityAttributes[i].attributeName()  == "term")
        {
            return entityAttributes[i].stringValue();
        }
    }
}

double EntityInstance::getPairGpa()
{
    for(unsigned int i = 0; i < entityAttributes.size(); i++){
        if(  entityAttributes[i].attributeName()  == "gpa")
        {
            return entityAttributes[i].numberValue();
        }
    }
}