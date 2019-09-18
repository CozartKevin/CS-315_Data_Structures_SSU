//
// Created by Kevin on 9/17/2019.
//

#include "count_inversions_iterative.hpp"
#include <vector>

int count_Inversion(std::vector<int> &InputVector, int vSize){
int totalInversions = NULL;
    if(vSize == 0){
        return 0;
    }

        if(InputVector[vSize - 1] > InputVector[vSize]){
         totalInversions =  1;
        }
    return totalInversions + count_Inversion(InputVector, (vSize - 1));
}