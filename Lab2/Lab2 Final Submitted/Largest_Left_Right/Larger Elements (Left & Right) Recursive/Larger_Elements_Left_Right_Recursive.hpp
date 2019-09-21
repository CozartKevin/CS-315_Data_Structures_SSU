//
// Created by Kevin on 9/17/2019.
//
#include <vector>

#ifndef LARGER_ELEMENTS_LEFT_RIGHT_RECURSIVE_HPP
#define LARGER_ELEMENTS_LEFT_RIGHT_RECURSIVE_HPP
void largest_left_right_recursive(const std::vector<int> &InputVector, std::vector<int> &OutputVector, int n);
void check_Rest_Left_Vect(const std::vector<int> &InputVector,std::vector<int> &OutputVector, int currentVectorLocation, int count);
void larger_Elements_Right(const std::vector<int> &InputVector, std::vector<int> &OutputVector,int currentVectorLocationRight, int count);
#endif //LARGER_ELEMENTS_LEFT_RIGHT_RECURSIVE_HPP
