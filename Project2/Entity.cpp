//
// Created by Kevin on 11/5/2019.
//
#include <iostream>
#include "Entity.hpp"


Entity::Entity()
{
_numberOfInstances = 0;
}

void Entity::addObject(EntityInstance & instanceToPush)
{
    _numberOfInstances++;

    instances.push_back(instanceToPush);
}

void Entity::print()
{
    std::cout << "[" << std::endl;
    for(unsigned int j = 0; j < instances.size();j++){
        // std::cout << '\n';
        instances[j].print();
        if(j+1 < instances.size()){
            std::cout << "," << std::endl;
        }
    }
    std::cout << "]" << std::endl;
}

int Entity::numberOfInstances()
{
    return _numberOfInstances;
}

Entity Entity::intersection(Entity e)
{

    e.find(this[0].getID());

    return;
}

//TODO write find for intersection on entities. returns entity
//TODO write getID for Entity that get ID that returns the outcome from Entity Instance's getPairID
//TODO write getPairID which returns the ID string that is in the instance.
//TODO write find for Entity that checks the Pair ID of another entity for the string you input.

Entity Find(){
    this = e
}
void Entity::setIds(EntityInstance ei)
{
    ei.getPairID();
    ei.getPairGPA();

}
