//
// Created by Kevin on 9/17/2019.
//

#include "Larger_Elements_Left_Right_Recursive.hpp"
#include <vector>
#include <iostream>

void largest_left_right_recursive(const std::vector<int> &InputVector, std::vector<int> &OutputVector, int i)
{

    if (i == 0)
    {
        return;
    }
    if (i == 1)
    {
        OutputVector[0] = 0;
        larger_Elements_Right(InputVector, OutputVector, (i - 1), (i - 1));
    }
    if (InputVector[i] < InputVector[i - 1])
    {

        OutputVector[i] = InputVector[i - 1];
        larger_Elements_Right(InputVector, OutputVector, i, i);
    }
    else
    {
        check_Rest_Left_Vect(InputVector, OutputVector, i, i);
        larger_Elements_Right(InputVector, OutputVector, i, i);
    }
    largest_left_right_recursive(InputVector, OutputVector, (i - 1));


}

void
check_Rest_Left_Vect(const std::vector<int> &InputVector, std::vector<int> &OutputVector, int currentVectorLocation,
                     int count)
{
    int replaceLocation = currentVectorLocation;
    if (count == 0)
    {
        OutputVector[replaceLocation] = 0;
        return;
    }

    if (InputVector[replaceLocation] < InputVector[count])
    {
        OutputVector[replaceLocation] = InputVector[count];
        return;
    }
    else
    {

    }
    check_Rest_Left_Vect(InputVector, OutputVector, currentVectorLocation, (count - 1));

}

void larger_Elements_Right(const std::vector<int> &InputVector, std::vector<int> &OutputVector,
                           int currentVectorLocationRight, int countRight)
{

    if (countRight == (InputVector.size()))
    {
        return;
    }
    if (currentVectorLocationRight == (InputVector.size() - 1))
    {
        return;
    }
    if (InputVector[currentVectorLocationRight] < InputVector[countRight])
    {
        if (InputVector[countRight] > OutputVector[currentVectorLocationRight])
        {
            OutputVector[currentVectorLocationRight] = InputVector[countRight];
            return;
        }
        else
        {
            return;
        }

    }
    larger_Elements_Right(InputVector, OutputVector, currentVectorLocationRight, (countRight + 1));

}
