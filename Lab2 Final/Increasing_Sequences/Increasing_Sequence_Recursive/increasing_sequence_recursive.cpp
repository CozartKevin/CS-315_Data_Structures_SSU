//
// Created by Kevin on 9/17/2019.
//

#include "increasing_sequence_recursive.hpp"
#include <vector>
#include <iostream>
int sequenceCount = 1;
int largestCount = NULL;
int increasing_sequence_recursive(std::vector<int> &numbers, int startIdx){

 if(startIdx + 1 == numbers.size()){
     return largestCount;
 }
        if(numbers[startIdx] <= numbers[startIdx + 1]){
           sequenceCount++;
        }else{
            sequenceCount = 1;
        }
        if(sequenceCount > largestCount){
            largestCount = sequenceCount;
        }
    if(startIdx <= (numbers.size() - 1)){
        increasing_sequence_recursive(numbers, (startIdx + 1));
    }
}