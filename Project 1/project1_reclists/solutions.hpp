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

bool member(list p, list q);

bool two_the_same(list p, list q);

list flat(list p);

list permute(list p);

list list_pair(list p, list q);

bool equal(list p, list q);

list shape(list p);

list total_reverse(list p);

list intersection(list p, list q);

list list_union(list p, list q);

#endif
