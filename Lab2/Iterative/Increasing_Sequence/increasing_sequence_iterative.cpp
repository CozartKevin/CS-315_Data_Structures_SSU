//
// Created by Kevin on 9/17/2019.
//

#include "increasing_sequence_iterative.hpp"
#include <vector>

int increasing_sequence_iterative(std::vector<int> &numbers){
int sequenceCount = 1;
int largestCount = NULL;
    for(int i = 0; i < numbers.size() -1 ; i++){
        if(numbers[i] <= numbers[i + 1]){
           sequenceCount++;
        }else{
            sequenceCount = 1;
        }
        if(sequenceCount > largestCount){
            largestCount = sequenceCount;
        }
    }
    return largestCount;
}