//
// Created by Kevin on 9/17/2019.
//

#include "count_inversions_iterative.hpp"
#include <vector>

int count_Inversion(std::vector<int> &InputVector){
int totalInversions = NULL;
    for(int i = 0; (i + 1) < InputVector.size(); i++){
        if(InputVector[i] > InputVector[i + 1]){
           totalInversions++;
        }
    }
    return totalInversions;
}