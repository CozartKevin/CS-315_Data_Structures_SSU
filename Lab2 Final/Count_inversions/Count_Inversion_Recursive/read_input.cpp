//
// Created by Kevin on 9/17/2019.
//
#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include "read_input.hpp"

void read_numbers(std::string fileName, std::vector<int> &v){

    std::ifstream inFile(fileName);
    // Make sure the file stream is good
    long n = 0;
    while(!inFile.eof()) {
        inFile >> n;
        v.push_back(n);
    }
}


