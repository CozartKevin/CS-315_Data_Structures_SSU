#include<stdlib.h>
#include "TreeNode.hpp"
#include <stack>
class BinSearchTree {
public:
    void insert( int v );
    bool find( int v );
    TreeNode *findParent(int v);
    bool iterFind( int v );
    int size();
    void inorderDump();
    int  maxDepth();
    void levelOrderDump();
    bool remove(int v);
    int iterMaxDepth();
    int kthSmallest(int k);

    ~BinSearchTree();
private:
    TreeNode *local_insert( TreeNode *, int );
    bool local_find( TreeNode * root, int v);
    TreeNode *local_findParent(TreeNode *root, int v);
    bool local_iterFind(TreeNode *root, int v);
    int local_size(TreeNode * root);
    void local_inorderDump(TreeNode * root);
    int local_maxDepth(TreeNode * root);
    void local_levelOrderDump(TreeNode * root);
    TreeNode *local_remove(TreeNode * root, int v);
    TreeNode *nextLargestValue(TreeNode * root);
    int local_iterMaxDepth(TreeNode * root);
    TreeNode *local_kthSmallest(TreeNode * root, int k, std::stack<TreeNode*> *inOrderTreeNodeStack);

    TreeNode *root = nullptr;
};
