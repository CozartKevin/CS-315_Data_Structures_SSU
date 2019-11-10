//
// Created by Raggdoll on 11/3/2019.
//

#ifndef PROJECT2_JSONTOKENIZER_HPP
#define PROJECT2_JSONTOKENIZER_HPP

#include <string>
#include <fstream>
#include "JSONToken.hpp"

class JSONTokenizer {




public:
    JSONTokenizer(std::string);
    JSONToken getToken();

private:
    std::string inputFileName;
    std::ifstream inputStream;


    bool charOfInterest(char c);

    std::string &getString(char c,std::string &tagName, std::istream &inputStream) const;


};





#endif //PROJECT2_JSONTOKENIZER_HPP
