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
    if(is_null(q)){
        return false;
    }
    if(is_atom(car(q))){
        if(eq(p,car(q))){
            return true;
        }else{

           return  member(p, cdr(q));
        }
    }else {
        std::cout << " Inside else after not is atom on car q" << std::endl;
        if (member(p, car(q))) {
            return true;
        } else {
            return member(p, cdr(q));
        }
    }

    return member(p,cdr(q));

    if(is_null(cdr(q))){
        return false;
    }
    if(car(q) == p){
        return true;
    }

    return member(p, cdr(q));

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

bool is_lat(list p){

    if(is_null(p)){
    return true;
    }

    if(is_atom(car(p))){
    std::cout << "  Inside is atom of is lat" << std::endl;
        return is_lat(cdr(p));
    }
    return false;

}

list last(list p){


    if(is_null(p)){
        return 0;
    }

   if(is_null(cdr(p))){
       return car(p);
   }
    return last(cdr(p));
}
list outputList = NULL;
list previousList = NULL;
list firsts(list p){
    std::cout << " Before IF in firsts" << std::endl;
    if(p->first != NULL && p->first->type != ATOMS){
        std::cout << " inside p first != null and First type != atoms" << std::endl;\
        previousList = p;
        p = car(p);
    }else if(p->first->type == ATOMS)
    {
        std::cout << " Inside p first type atoms" << std::endl;
        outputList = append(p, outputList);
        write_list(p);
        write_list(outputList);
        cdr(p);

    }else if(p->rest == NULL && p->first == NULL){
        std::cout << " Inside rest == null and first == null" << std::endl;
        return outputList;

    }else{
        p = cdr(p);
    }
    firsts(p);

}


bool two_the_same(list p, list q){
}