#include <iostream>
#include "TreeNode.hpp"
#include "BinSearchTree.hpp"

int main( int argc, char *argv[] ) {
    // create a tree and then print the values of its nodes
    // from the smallest to the largest.

    BinSearchTree *tree = new BinSearchTree();
    BinSearchTree *tree2 = new BinSearchTree();
    int v;
    std::cout << "Insert Values for Tree" << std::endl;
    while( std::cin >> v ) {
        std::cout << v << std::endl;
        tree->insert( v );
    }
    std::cin.clear();
    int j;
    std::cout << "Insert Values for Tree" << std::endl;
    while( std::cin >> j ) {
        std::cout << j << std::endl;
        tree2->insert( j );
    }
                         //  std::cout << tree->iterFind(10) << " Iter find 10 return" << std::endl;
                          // std::cout << tree->iterFind(100) << " Iter find 100 return" << std::endl;
                          // std::cout << tree->find(10) << " Tree find 10 return" << std::endl;
                       // std::cout << tree->find(100) << " Tree find 100 return" << std::endl;
    std::cout << tree->size() << " Size output" << std::endl;
                        //   tree->levelOrderDump();
    tree->inorderDump();
    std::cout << tree->maxDepth() << " Max Depth output" << std::endl;
                      // std::cout << tree->iterMaxDepth() << " iter Max Depth output" << std::endl;
    tree->valuesAtlevel(2);
    std::cout << " Values at level Output" << std::endl;
    tree->iterValuesAtLevel(2);
    std::cout << " iterValues at level output" << std::endl;

    std::cout << tree->hasRootToLeafSum(12) << " Root to leaf sum OUTPUT" << std::endl;
    std::cout << tree->kthSmallest(3) << " kthSmallest Output" << std::endl;
                   //std::cout << tree->remove(10) << " Remove 10 output" << std::endl;
    std::cout << tree->areIdentical(tree2) << " are identical OUTPUT" << std::endl;
    std::cout << tree->intersectWith(tree2) << " Intersect with OUTPUT" << std::endl;

    return 0;
}