//
// Created by Kevin on 9/17/2019.
//

#include "Larger_Elements_Left_Right_iterative.hpp"
#include <vector>
#include <iostream>

void larger_Elements_Left(std::vector<int> &InputVector, std::vector<int> &OutputVector)
{
int step = 0;
    for(int i = (InputVector.size() - 1); i > 0; i--)
    {
        if (i == 1)
        {
            OutputVector[0] = 0;
        }
        if (InputVector[i] < InputVector[i - 1])
        {

            OutputVector[i] = InputVector[i - 1];
            step = 1;
            larger_Elements_Right(InputVector, OutputVector, i, stepCount);
        }
        else
        {
            check_Rest_Left_Vect(InputVector, OutputVector, i, stepCount);

        }
        larger_Elements_Right(InputVector, OutputVector, i);
    }

}

void check_Rest_Left_Vect(std::vector<int> &InputVector, std::vector<int> &OutputVector, int currentVectorLocation)
{
    int replaceLocation = currentVectorLocation;
    for(int i = currentVectorLocation - 1; i >= 0; i--)
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

void larger_Elements_Right(std::vector<int> &InputVector, std::vector<int> &OutputVector, int currentVectorLocationRight,int stepCount){
int replaceLocation = currentVectorLocationRight;
    for(int j = 0; (j < stepCount; j++)
    {
            check_Rest_Right_Vect(InputVector, OutputVector, j,stepCount);
    }

}
void check_Rest_Right_Vect(std::vector<int> &InputVector,std::vector<int> &OutputVector, int currentVectorLocationRightRest,int stepCount){
    int replaceLocation = currentVectorLocationRightRest;
    for(int k = currentVectorLocationRightRest; k < (InputVector.size() - 1); k++)
    {
        if (InputVector[replaceLocation] < InputVector[k + 1])
        {
            if(InputVector[k + 1] > OutputVector[replaceLocation]){
                OutputVector[replaceLocation] = InputVector[k + 1];
            }
        }
    }
}