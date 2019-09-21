//
// Created by Kevin on 9/17/2019.
//
#include <vector>

#ifndef LARGER_ELEMENTS_LEFT_RIGHT_ITERATIVE_HPP
#define LARGER_ELEMENTS_LEFT_RIGHT_ITERATIVE_HPP
void larger_Elements_Left(std::vector<int> &InputVector, std::vector<int> &OutputVector,int stepCount);
void check_Rest_Left_Vect(std::vector<int> &InputVector,std::vector<int> &OutputVector, int currentVectorLocation,int stepCount);
void larger_Elements_Right(std::vector<int> &InputVector, std::vector<int> &OutputVector,int currentVectorLocationRight,int stepCount);
void check_Rest_Right_Vect(std::vector<int> &InputVector,std::vector<int> &OutputVector, int currentVectorLocationRightRest,int stepCount);


#endif //LARGER_ELEMENTS_LEFT_RIGHT_ITERATIVE_HPP
