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
    Entity intersectedEntity;
    Entity tempEntity;

    for(unsigned int i = 0; i < instances.size(); i++){
        multiPass.insert(std::pair<std::string,EntityInstance>(getID(i),instances[i]));// ID TO SEARCH Entity e with)

    }
    for(unsigned int j = 0; j < e.instances.size(); j++){
        multiPass.insert(std::pair<std::string,EntityInstance>(e.getID(j),e.instances[j]));
    }

    for (std::multimap<std::string,EntityInstance>::iterator it=multiPass.begin(); it!=multiPass.end(); )
    {
        std::pair <std::multimap<std::string,EntityInstance>::iterator, std::multimap<std::string, EntityInstance>::iterator> it2;
        std::string key  = it->first;

        it2 = multiPass.equal_range(key);
        if(multiPass.count(key) >= 2)
        {
            //std::cout << it->first << std::endl;
            for (auto i = it2.first; i != it2.second; ++i)
            {
                tempEntity.addObject(i->second);
               // i->second.print();
            }
        }
            do
            {
                it++;
            } while (it != multiPass.end() && key == it->first);

    }

    for (int i = 0; i < tempEntity.entitySize(); i+=2)
    {

        Pair pair("curr_gpa", tempEntity.instances[i+1].getPairGpa());
        tempEntity.instances[i].addAttribute(pair);
        intersectedEntity.addObject(tempEntity.instances[i]);
    }

return intersectedEntity;
}

std::string Entity::getID(int index){
    return instances[index].getPairID();
}
std::string Entity::getTerm(int index){
    return instances[index].getPairTerm();
}
double Entity::getGpa(int index, bool getCur){
 if(!getCur)
 {
     return instances[index].getPairGpa();
 }else
 {
     return instances[index].getPairCurGpa();
 }

 }

int Entity::entitySize(){
    return instances.size();
}

void Entity::createGPABand()
{

    int prevSem = 0;
    int curSem = 0;
    for (int i = 0; i < entitySize(); i++)
    {
        if (getTerm(i) == "2187")
        {
            getGpa(i,false);
            getGpa(i,true);

            prevSem = getArrayPlace(i, false);
            curSem = getArrayPlace(i, true);
        }
        GPABand[prevSem][curSem]++;
    }
}

int Entity::getArrayPlace(int j, bool currentOrPrevious){

    int arrayPlace;
    if (getGpa(j, currentOrPrevious) > 3.67 && getGpa(j, currentOrPrevious) <= 4.0)
    {
        arrayPlace = 0;
    }
    else if (getGpa(j, currentOrPrevious) > 3.3 && getGpa(j, currentOrPrevious) <= 3.67)
    {
        arrayPlace = 1;
    }
    else if (getGpa(j, currentOrPrevious) > 3.0 && getGpa(j, currentOrPrevious) <= 3.3)
    {
        arrayPlace = 2;
    }
    else if (getGpa(j, currentOrPrevious) > 2.67 && getGpa(j, currentOrPrevious) <= 3.0)
    {
        arrayPlace = 3;
    }
    else if (getGpa(j, currentOrPrevious) > 2.3 && getGpa(j, currentOrPrevious) <= 2.76)
    {
        arrayPlace = 4;
    }
    else if (getGpa(j, currentOrPrevious) > 2.0 && getGpa(j, currentOrPrevious) <= 2.3)
    {
        arrayPlace = 5;
    }
    else if (getGpa(j, currentOrPrevious) > 1.67 && getGpa(j, currentOrPrevious) <= 2.0)
    {
        arrayPlace = 6;
    }
    else if (getGpa(j, currentOrPrevious) >= 0.0 && getGpa(j, currentOrPrevious) <= 1.67)
    {
        arrayPlace = 7;
    }
    else
    {
        std::cout << " GPA out of bounds " << getID(j) << " " << getTerm(j) << " " << getGpa(j, currentOrPrevious)
                  << std::endl;
    }

    return arrayPlace;
}

void Entity::printGPABand()
{
    std::cout << '[' << std::endl;
    for(int i = 0; i < 8; i++)
    {
        std::cout << '[';
        for(int j = 0; j < 8; j++)
        {
            std::cout <<   GPABand[i][j];
            if(j < 7){
                std::cout << ',';
            }
        }
        std::cout << ']';
        if(i < 7){
            std::cout << ',' ;
        }
        std::cout << std::endl;
    }
    std::cout << ']' << std::endl;
}

void Entity::outputGPABand(std::ofstream& GPAOutput)
{
    GPAOutput << '[' << std::endl;
    for(int i = 0; i < 8; i++)
    {
        GPAOutput << '[';
        for(int j = 0; j < 8; j++)
        {
            GPAOutput <<   GPABand[i][j];
            if(j < 7){
                GPAOutput << ',';
            }
        }
        GPAOutput << ']';
        if(i < 7){
            GPAOutput << ',' ;
        }
        GPAOutput << std::endl;
    }
    GPAOutput << ']' << std::endl;
}

void Entity::addInstanceAttribute(Pair &pair, int index)
{
    instances[index].addAttribute(pair);
}


