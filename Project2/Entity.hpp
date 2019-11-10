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

    void addObject(EntityInstance & instanceToPush);
    void print();    // prints all instances of this Entity.
    int numberOfInstances();
    Entity intersection(Entity e);
    void setIds(EntityInstance ei);
    void getID();
    // more member functions here.

private:
    std::vector<EntityInstance> instances;
    std::string id;
    int _numberOfInstances;
};

#endif //PROJECT2_ENTITY_HPP
