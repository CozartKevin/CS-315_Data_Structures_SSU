//
// Created by Kevin on 9/17/2019.
//

#include "Larger_Elements_Left_recursive.hpp"
#include <vector>
#include <iostream>

void largest_left_recursive(const std::vector<int> &numbers, std::vector<int> &result, int n)
{

        if (n == 0)
        {
            result[0] = 0;
            return;
        }
        if (numbers[n] < numbers[n - 1])
        {
            result[n] = numbers[n - 1];
        }
        else
        {
            check_Rest_Vect(numbers, result, n, (n - 1));

        }
    largest_left_recursive(numbers,result,(n - 1));

}

void check_Rest_Vect(const std::vector<int> &numbers, std::vector<int> &OutputVector, int currentVectorLocation,int decrementVectorLocaiton)
{
    if(decrementVectorLocaiton == 0 && !(numbers[currentVectorLocation] < numbers[decrementVectorLocaiton] ))
    {

        OutputVector[currentVectorLocation] = 0;
        return;
    }else{
        OutputVector[currentVectorLocation] = numbers[decrementVectorLocaiton];

    }
        if (numbers[currentVectorLocation] < numbers[decrementVectorLocaiton])
        {
            OutputVector[currentVectorLocation] = numbers[decrementVectorLocaiton];
            return;
        }
      check_Rest_Vect(numbers,OutputVector,currentVectorLocation,(decrementVectorLocaiton - 1));


}