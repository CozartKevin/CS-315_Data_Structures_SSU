//
// Created by Kevin on 9/17/2019.
//
#include <vector>

#ifndef Larger_Elements_Left_RECURSIVE_HPP
#define Larger_Elements_Left_RECURSIVE_HPP
void largest_left_recursive(const std::vector<int> &numbers, std::vector<int> &result, int n);
void check_Rest_Vect(const std::vector<int> &InputVector,std::vector<int> &OutputVector, int currentVectorLocation, int decrementVectorLocation);

#endif //Larger_Elements_Left_RECURSIVE_HPP
