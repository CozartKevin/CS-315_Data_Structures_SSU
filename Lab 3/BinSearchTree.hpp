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
    void valuesAtlevel(int k);
    void iterValuesAtLevel(int k);
    bool hasRootToLeafSum(int sum);
    bool areIdentical(BinSearchTree *bst);
    BinSearchTree *intersectWith(BinSearchTree *bst);
void deleteBinSearchTree(TreeNode * root);
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
    int local_kthSmallest(TreeNode * root, int k);
    void local_valuesAtLevel(TreeNode * root, int k);
    void local_iterValuesAtLevel(TreeNode * root, int k);
    bool local_hasRootToLeafSum(TreeNode * root, int sum);
    bool local_areIdentical(TreeNode * root, TreeNode * bstRoot);
    void *local_intersectWith(TreeNode * root, TreeNode * rootTop, TreeNode * bstRoot, TreeNode * bstRootTop, BinSearchTree * resultBST);

    TreeNode *root = nullptr;
};
