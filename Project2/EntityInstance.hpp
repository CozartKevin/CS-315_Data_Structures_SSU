//
// Created by Kevin on 11/5/2019.
//

#ifndef PROJECT2_ENTITYINSTANCE_HPP
#define PROJECT2_ENTITYINSTANCE_HPP
#include "Pair.hpp"
#include <vector>
#include <string>


class EntityInstance {
public:
    EntityInstance();
    void addAttribute(Pair &);
    int numAttributes();
   std::vector<std::string> &attributeNames();
    void print();   // prints this object
    // more member functions here.
    std::string getPairID();
    std::string getPairTerm();
    double getPairGpa();
    double getPairCurGpa();
private:
    std::vector<Pair> entityAttributes;

 //   std::vector<std::string> entityAttributeNames;
    int numberOfAttributes;

    // more variabl{}es here.
};

#endif //PROJECT2_ENTITYINSTANCE_HPP
