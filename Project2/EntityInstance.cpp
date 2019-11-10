//
// Created by Kevin on 11/5/2019.
//
#include <iostream>
#include "EntityInstance.hpp"
EntityInstance::EntityInstance(): numberOfAttributes{0}{
}
void EntityInstance::addAttribute(Pair &insertedPair){
    numberOfAttributes++;
    entityAttributeNames.push_back(insertedPair.attributeName());
    entityAttributes.push_back(insertedPair);

}

int EntityInstance::numAttributes(){
    return numberOfAttributes;
}

std::vector<std::string> & EntityInstance::attributeNames(){

return;
}


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