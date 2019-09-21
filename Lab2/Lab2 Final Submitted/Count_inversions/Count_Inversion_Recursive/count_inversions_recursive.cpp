//
// Created by Kevin on 9/17/2019.
//

#include "count_inversions_recursive.hpp"
#include <vector>
#include <iostream>

int totalInversion = 0; // I hate that this has global scope I know there is a better way to do this.

int count_Inversion(std::vector<int> &InputVector, int vSize)
{
    if(vSize == 0){
        return 0;

    }
    if((InputVector[(vSize - 1)] > InputVector[vSize])){
        totalInversion++;
    }
    if(vSize > 0){ // hate this organization its sloppy.
        count_Inversion(InputVector, (vSize - 1));
    }
    return totalInversion;
}