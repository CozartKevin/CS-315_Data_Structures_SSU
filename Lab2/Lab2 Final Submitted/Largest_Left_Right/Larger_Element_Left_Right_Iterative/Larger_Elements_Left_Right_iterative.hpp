//
// Created by Kevin on 9/17/2019.
//
#include <vector>

#ifndef LARGER_ELEMENTS_LEFT_RIGHT_ITERATIVE_HPP
#define LARGER_ELEMENTS_LEFT_RIGHT_ITERATIVE_HPP
void largest_left_right_iterative(const std::vector<int> &InputVector, std::vector<int> &OutputVector);
void check_Rest_Left_Vect( const std::vector<int> &InputVector,std::vector<int> &OutputVector, int currentVectorLocation);
void larger_Elements_Right(const std::vector<int> &InputVector, std::vector<int> &OutputVector,int currentVectorLocationRight);



#endif //LARGER_ELEMENTS_LEFT_RIGHT_ITERATIVE_HPP
