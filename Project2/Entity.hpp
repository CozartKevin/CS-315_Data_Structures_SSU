//
// Created by Kevin on 11/5/2019.
//

#ifndef PROJECT2_ENTITY_HPP
#define PROJECT2_ENTITY_HPP
#include <vector>
#include <map>
#include <fstream>
#include "EntityInstance.hpp"

class Entity {
public:
    Entity();

    void addObject(EntityInstance & instanceToPush);
    void print();    // prints all instances of this Entity.
    int numberOfInstances();
    Entity intersection(Entity e);
    std::string getID(int index);
    std::string getTerm(int index);
    double getGpa(int index);
    int entitySize();
    void createGPABand();
    void printGPABand();
    void outputGPABand(std::ofstream& GPAOutput);
    // more member functions here.

private:
    std::vector<EntityInstance> instances;
    std::multimap<std::string, EntityInstance> multiPass;
    int _numberOfInstances;
    int GPABand[8][8] = { };

    int getArrayPlace(int i);

};

#endif //PROJECT2_ENTITY_HPP
