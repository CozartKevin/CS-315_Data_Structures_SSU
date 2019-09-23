#include<iostream>
#include<stdlib.h>
//#include<unistd.h>

#include"reclists.hpp"
#include "solutions.hpp"

using namespace std;


const int LINE_LEN = 72;                // for safe screen width.
const char *LEADER = "  ";
const int LENofLEADER = strlen(LEADER); // length of above.
int line_used = 0;

void write_item(list p);
void emit( const char str[] );
void write_list(list p)
{
    // writes the external representation of  p  -- assumes that  p  has been
    // defined by  readlist  or through the use of above functions.
    write_item(p);
    cout << endl;
}

void emit( const char str[] )
{

    int len = strlen( str );
    if( line_used + len + 1 > LINE_LEN ) {
        cout << endl;
        cout << LEADER;  // indent subsequent lines.
        line_used = LENofLEADER;
    }
    line_used = line_used + len + 1;
    cout << ' ';
    cout << str;
}

const char *NILSYM = "()";
const char *LEFT_PAREN = "(";
const char *RIGHT_PAREN = ")";

void write_item(list p)
{
    if( is_null(p) ) emit(NILSYM);
    else if( is_atom(p) )
        emit(p->atom);
    else {
        emit(LEFT_PAREN);
        do {
            write_item(car(p));
            p = cdr(p);
        } while ( ! is_null(p) );
        emit(RIGHT_PAREN);
    }
}


list null()
{
    return 0;
}

bool is_null( list p )
{
    return p == 0;
}

bool is_atom( list p )
{
    return ! is_null(p) && p->type == ATOMS;
}

list cdr(list p)
{
    // return remainder of list -- dies if  p  is a empty list or an atom.
    if( is_null(p) || is_atom(p) ) {
        cout << "ERROR in cdr:  cdr has been called either with an empty list or an atom.  Input list is:\n";
        write_list( p );
        exit( 1 );
    }
    return p->rest;
}


list  car( list p)
{
    // return first element of list -- dies if p is a empty list or an atom.
    if( is_null(p) || is_atom(p) ) {
        cout << "ERROR in car:  car has been called either with an empty list or an atom.  Input list is:\n";
        write_list( p );
        exit( 1 );
    }
    return  p->first;
}

bool eq( list p, list q )
{
    if( ! is_atom(p) || ! is_atom(q) ) return 0;
    return strcmp( p->atom, q->atom ) == 0;
}

bool is_lat(list p){
return true;
}

list previousList = NULL;
list last(list p){
    if((p->rest != NULL) && cdr(p)->type == LISTS){
        if(p->first != NULL)
        {
            previousList = p;
        }
        p = cdr(p);
    }else if((p->first != NULL) && car(p)->type != ATOMS)
    {
        p = car(p);
    }else if(p->first == NULL){
        p = previousList;
             if(p->first->type == ATOMS){
            return p->first;
        } else {
                 p = car(p);
             }
    }else
    {
        return p->first;
    }

last(p);
}

list outputList = NULL;
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