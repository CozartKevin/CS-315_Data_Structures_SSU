#include<iostream>
#include"reclists.hpp"
#include"solutions.hpp"

using namespace std;


int main()
{

    std::cout << "Enter a recursive list for atoms at level: ";
    list p = read_list();
    std::cout << "Enter level: ";
    int level;
    std::cin >> level;
    std::cout << " letter for compare ";
    list q = read_list();
    write_list(q);
    std::cout << member(q, p) << " Member output" << std::endl;
    std::cout  << is_lat(p) << " Is Lat Output " <<  std::endl;
    std::cout << " Before last Call";
    p = last(p);
    std::cout << " Write List P" << std::endl;
    write_list(p);
    std::cout << " After last call" << std::endl;
    std::cout << "atomsAtLevel says ";
    //write_list(atomsAtLevel(p, level));

    /*

    std::cout << "Enter a recursive list for total reverse: ";
    list p = read_list();
    std::cout << "total reverse says\n";
    write_list(total_reverse(p));

    std::cout << "Printing the list... ";

    std::cout << "The 3rd sublist of the input list is :";
    write_list( nthSublist(p, 3) );

     */
//    std::cout << "The input list has " << numSublists(p) << " sublists.\n";

#ifdef __A_NON_DEFINED_NAME

    std::cout << "Starting main..." << std::endl;
    list p;

    cout << "Enter a list to counts the number of atoms in it: ";
    p = read_list();
    cout << "The list has " << numAtoms(p) << " atoms at the top level.\n";


// Move the following pre-processor line down as you write a solution for each of
// the functions.



    list p, q;

     cout << "Enter two lists for append: ";
     p = read_list();
     q = read_list();
     write_list( append(p, q) );

     cout << "Enter a list for reverse: ";
     p = read_list();
     write_list( reverse(p) );


     // is_lat
     cout << "Enter a list for is_lat: ";
     p = read_list();
     write_list( p );
     if( is_lat(p) )
         cout << "is_lat:: The above list is an atomic list; a list of atoms.\n";
     else cout << "is_lat:: The above list is not an atomic list\n";

     // member
     cout << "Enter two lists for member (an atom followed by a list):\n";
     p = read_list();
     q = read_list();
     if( member(p, q) )
         cout << "Is a member\n";
     else
         cout << "Is not a member\n";

     // last
     cout << "Enter a list for last: ";
     p = read_list();
     write_list( p );
     write_list( last( p ) );

     // list-pair
     cout << "Enter two lists for list-pair: ";
     p = read_list();
     q = read_list();
     write_list( list_pair(p, q) );

     // firsts
     cout << "Enter a list for firsts: ";
     p = read_list();
     write_list( firsts(p) );

     // flat
     cout << "Enter a list for flat: ";
     p = read_list();
     cout << "Output list for flat is: " << endl;
     write_list( flat( p ) );

     // two_the_same
     cout << "Enter two lists for two_the_same: ";
     p = read_list();
     q = read_list();
     cout << two_the_same(p, q) << endl;

     // equal
     cout << "Enter two lists for equal: ";
     p = read_list();
     q = read_list();
     cout << equal(p, q) ) << endl;

     // total_reverse
     cout << "Enter a list for total reverse: ";
     p = read_list();
     write_list( total_reverse(p) );

     // shape
     cout << "Enter a list for shape: ";
     write_list( shape( read_list() ) );

     //  Intersection
     cout << "Enter two lists for intersection: ";
     p = read_list();
     q = read_list();
     write_list( intersection(p, q) );

     //  List-Union
     cout << "Enter two lists for list_union: ";
     p = read_list();
     q = read_list();
     write_list( list_union(p, q) );

     // permute
     cout << "Enter a list for permute: ";
     write_list( permute( read_list() ) );
#endif
    return 0;
}
