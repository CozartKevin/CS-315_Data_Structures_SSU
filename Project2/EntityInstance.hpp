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
    void addAttribute(Pair &);
    int numAttributes();
    std::vector<std::string> &attributeNames();
    void print();   // prints this object
    // more member functions here.

private:
    std::vector<Pair> entityAttributes;
    // more variables here.
};

#endif //PROJECT2_ENTITYINSTANCE_HPP
