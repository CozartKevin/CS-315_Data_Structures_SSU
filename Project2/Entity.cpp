//
// Created by Kevin on 11/5/2019.
//
#include <iostream>
#include <vector>
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

    for(unsigned int i = 0; i < instances.size(); i++){
        multiPass.insert(std::pair<std::string,EntityInstance>(getID(i),instances[i]));// ID TO SEARCH Entity e with)

    }
    for(unsigned int j = 0; j < e.instances.size(); j++){
        multiPass.insert(std::pair<std::string,EntityInstance>(e.getID(j),e.instances[j]));
    }
std::cout << " MULTI PASS PRINT OUT" << std::endl;


    for (std::multimap<std::string,EntityInstance>::iterator it=multiPass.begin(); it!=multiPass.end(); )
    {
        std::pair <std::multimap<std::string,EntityInstance>::iterator, std::multimap<std::string, EntityInstance>::iterator> it2;
        std::string key  = it->first;

        it2 = multiPass.equal_range(key);

        std::cout << it->first << std::endl;
        for (auto i = it2.first; i != it2.second; ++i)
        {
            //TODO INSERT INTO new Entity with all gpa and terms but only one ID.
            // New Entity
            // Combine Entity Instances for the same ID
            // Push new Entity Instance with all ID into new Entity
            i->second.print();
        }
        do
        {
            it++;
        }while(it != multiPass.end() && key == it->first);

    }
return e;
}

//TODO write find for intersection on entities. returns entity
//TODO write getID for Entity that get ID that returns the outcome from Entity Instance's getPairID
//TODO write getPairID which returns the ID string that is in the instance.
//TODO write find for Entity that checks the Pair ID of another entity for the string you input.



std::string Entity::getID(int index){
    return instances[index].getPairID();
}
std::string Entity::getTerm(int index){
    return instances[index].getPairTerm();
}
double Entity::getGpa(int index){
    return instances[index].getPairGpa();
}