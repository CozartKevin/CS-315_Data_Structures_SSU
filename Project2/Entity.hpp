//
// Created by Kevin on 11/5/2019.
//

#ifndef PROJECT2_ENTITY_HPP
#define PROJECT2_ENTITY_HPP
#include <vector>
#include "EntityInstance.hpp"

class Entity {
public:
    Entity();

    void addObject(EntityInstance &);
    void print();    // prints all instances of this Entity.
    // more member functions here.

private:
    std::vector<EntityInstance> instances;
};

#endif //PROJECT2_ENTITY_HPP
