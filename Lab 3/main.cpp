#include <iostream>
#include "TreeNode.hpp"
#include "BinSearchTree.hpp"

int main( int argc, char *argv[] ) {
    // create a tree and then print the values of its nodes
    // from the smallest to the largest.

    BinSearchTree *tree = new BinSearchTree();

    int v;
    std::cout << "Insert Values for Tree" << std::endl;
    while( std::cin >> v ) {
        std::cout << v << std::endl;
        tree->insert( v );
    }
    std::cout << tree->find(10) << " Tree find 10 return" << std::endl;
    std::cout << tree->find(100) << " Tree find 100 return" << std::endl;

    tree->inorderDump();
    return 0;
}