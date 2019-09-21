//
// Created by Kevin on 9/17/2019.
//

#include "Larger_Elements_Left_iterative.hpp"
#include <vector>
#include <iostream>

void larger_Elements_Left(std::vector<int> &InputVector, std::vector<int> &OutputVector)
{

    for (int i = (InputVector.size() - 1); i > 0; i--)
    {
        if (i == 1)
        {
            OutputVector[0] = 0;
        }
        if (InputVector[i] < InputVector[i - 1])
        {
            OutputVector[i] = InputVector[i - 1];
        }
        else
        {
            check_Rest_Vect(InputVector, OutputVector, i);

        }
    }

}

void check_Rest_Vect(std::vector<int> &InputVector, std::vector<int> &OutputVector, int currentVectorLocation)
{
    int replaceLocation = currentVectorLocation;
    for (int i = currentVectorLocation - 1; i >= +0; i--)
    {
        if (InputVector[replaceLocation] < InputVector[i])
        {
            OutputVector[replaceLocation] = InputVector[i];
            return;
        }
        else
        {

        }
    }
    OutputVector[replaceLocation] = 0;
}