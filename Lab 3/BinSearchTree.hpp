#include<stdlib.h>
#include "TreeNode.hpp"

class BinSearchTree {
public:
    void insert( int v );
    bool find( int v );
    bool iterFind( int v );
    void inorderDump();
    int  maxDepth();

    ~BinSearchTree();
private:
    TreeNode *local_insert( TreeNode *, int );
    bool find( TreeNode * root, int v);

    TreeNode *root = nullptr;
};
