//
// Created by Kevin on 9/17/2019.
//

#include "Larger_Elements_Left_Right_iterative.hpp"
#include <vector>
#include <iostream>

void largest_left_right_iterative(const std::vector<int> &InputVector, std::vector<int> &OutputVector)
{

    for(int i = (InputVector.size() - 1); i > 0; i--)
    {
        if (i == 1)
        {
            OutputVector[0] = 0;
            larger_Elements_Right(InputVector, OutputVector, i - 1);
        }
        if (InputVector[i] < InputVector[i - 1])
        {

            OutputVector[i] = InputVector[i - 1];
            larger_Elements_Right(InputVector, OutputVector, i);
        }
        else
        {
            check_Rest_Left_Vect(InputVector, OutputVector, i);
            larger_Elements_Right(InputVector, OutputVector, i);
        }

    }

}

void check_Rest_Left_Vect(const std::vector<int> &InputVector, std::vector<int> &OutputVector, int currentVectorLocation)
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

void larger_Elements_Right(const std::vector<int> &InputVector, std::vector<int> &OutputVector, int currentVectorLocationRight){
    int replaceLocation = currentVectorLocationRight;
    for(int j = currentVectorLocationRight; (j < InputVector.size() - 1); j++)
    {
        if(currentVectorLocationRight == (InputVector.size() - 1)){
            return;
        }
        check_Rest_Right_Vect(InputVector, OutputVector, j);
    }
}
void check_Rest_Right_Vect(const std::vector<int> &InputVector,std::vector<int> &OutputVector, int currentVectorLocationRightRest){
    int replaceLocation = currentVectorLocationRightRest;
    for(int k = currentVectorLocationRightRest; k < (InputVector.size() - 1); k++)
    {
        if (InputVector[replaceLocation] < InputVector[k])
        {
            if(InputVector[k] > OutputVector[replaceLocation]){
                OutputVector[replaceLocation] = InputVector[k];
                return;
            } else{
                return;
            }

        }
    }
}

