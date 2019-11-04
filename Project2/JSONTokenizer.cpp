//
// Created by Raggdoll on 11/3/2019.
//
#include <iostream>
#include <fstream>
#include "JSONTokenizer.hpp"
 JSONTokenizer::JSONTokenizer(std::string name) :
                                         inputFileName{name}
{
    inputStream.open(inputFileName,
                     std::ios::in);  // open the input file. We will make sure that it is open in getToken.
}


bool JSONTokenizer::charOfInterest(char c)
{
    // is c the initial (or the sole) character of a token?
    if (c == '[')
    {
        return true;
    } else if (c == ']')
    {
        return true;
    }
    else if (c == '{')
    {
        return true;
    }else if (c == '}')
    {
        return true;
    }else if (c == ':')
    {
        return true;
    }
    else if (c == ',')
    {
        return true;
    }
    else if (c == '"') //TODO Concerned that '"' wont compare properly.  Test it.
    {
      //  std::cout << " inside iffy compare " << std::endl;
        return true;
    }
    else
    {
        return false;
    }
}
JSONToken JSONTokenizer::getToken()
{
    char c;

    if (!inputStream.is_open())
    {
        std::cout << "Tokenizer::getToken() called with a stream that is not open." << std::endl;
        std::cout << "Make sure that " << inputFileName << " exists and is readable. Terminating.";
        exit(2);
    }

    while (inputStream.get(c) && !charOfInterest(c))
    {

    }

    JSONToken jsontoken;
    if (inputStream.eof())
    {
        jsontoken.endOfFile() = true;
        return jsontoken;
    }

    if (c == '[' || c == ']' || c == '{' || c == '}'|| c == ',')
    {
        jsontoken.makeTag(c);
        return jsontoken;
    }else if(c == ':'){
      while(inputStream.get(c) != '"' || isdigit(inputStream.get(c))){

      }
      if(c == '"'){
            inputStream.putback(c);
            jsontoken.makeTag(':');
            return jsontoken;
      }
      if(isdigit(c)){
          std::string tagName;
          tagName = getString(c, tagName, inputStream);
          jsontoken.makeTag(tagName);
          return jsontoken;
      }


    }else if (c == '"')//TODO same todo as earlier ' " ' comparison.
    {
     //   std::cout << " Inside iffy compare 2.0 before tagname set" << std::endl;
        std::string tagName;
        tagName = getString(c, tagName, inputStream);
     //   std::cout << tagName << " after GetString" << std::endl;
      //  std::cout << " before tagname Make for jsontoken" << std::endl;
        jsontoken.makeTag(tagName);
      //  std::cout << " jsontoken tagname before return" << std::endl;
      //  jsontoken.print();
        return jsontoken;
    }

std::cout <<  " End of get Token,  call ran away" << std::endl;
}



std::string &JSONTokenizer::getString(char c, std::string &tagName, std::istream &inputStream) const
{

    do
    {
        inputStream.get(c);
        tagName = tagName + c;
      //  std::cout << tagName << " Tagname in loop" << std::endl;
    } while (inputStream.peek() != '"'&& !inputStream.eof());
   // std::cout << tagName << " Tagname after getString" << std::endl;
    inputStream.get(c);
  //  std::cout << " before tagname return" << std::endl;
    return tagName;
}