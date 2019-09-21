#include "reclists.hpp"
#include "solutions.hpp"

// As you implement functions in this file, you should add the
// function-prototype to the solutions.hpp. The function-prototypes
// for append and reverse are already in solutions.hpp.

int numSublists(list p) {
    if(is_null(p))
        return 0;

    return numSublists(cdr(p)) + 1;
}

list nthSublist(list p, int n) {
    if( n == 1 )
        return car(p);

    return nthSublist(cdr(p), n - 1);
}

int numAtoms(list p) {
    if(is_null(p))
        return 0;

    if( is_atom( car(p) ))
        return 1 + numAtoms(cdr(p));

    return numAtoms(cdr(p));

}
bool member(list p, list q) {
    // p is an atom. q is a list of atoms. The function
    // returns true if p is one of the atoms in q. Otherwise,
    // it return false.
    return true;
}

list append(list p, list q) {
    if(is_null(p))
        return q;
    return cons(car(p), append(cdr(p), q));
}

list atomsAtLevel(list p, int level) {
    if(level == 0 || is_null(p))
        return null();

    if(is_atom(car(p)))
        return level == 1 ? cons(car(p), atomsAtLevel(cdr(p), level)) :
                                         atomsAtLevel(cdr(p), level);
    return append(atomsAtLevel(car(p), level -1 ), atomsAtLevel(cdr(p), level));
}
