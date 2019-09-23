#ifndef __MYSOLUTION_HPP
#define __MYSOLUTION_HPP

#include<iostream>
#include"reclists.hpp"

int numSublists(list p);
list nthSublist(list p, int n);

list append(list p, list q);
list atomsAtLevel(list p, int level);


bool is_lat(list p);
//takes non-atomic list and returns true if the list is a list (potentially empty) of atoms.

list last(list p);
//returns the last element, l[n], of a non-atomic, non-empty list.
list firsts(list p);



#endif
