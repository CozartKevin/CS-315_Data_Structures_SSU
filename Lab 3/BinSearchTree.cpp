//
// Created by Kevin on 10/8/2019.
//
#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include "TreeNode.hpp"
#include "BinSearchTree.hpp"

/*
 * local_insert
 * var in: TreeNode, integer
 * var out: TreeNode
 * local_insert takes a TreeNode root and an integer v and if the TreeNode root is a nullPtr it creates a new TreeNode with the value v
 * if the TreeNode root is not a nullptr then local_insert will the appropriate place for the value and insert it there.
 *  returns the modified TreeNode root
 */
 TreeNode *BinSearchTree::local_insert( TreeNode *root, int v ) {
    if( root == nullptr )
        return new TreeNode( v );
    //Rewritten code that was given to use from Teacher
    //  root->value() < v ? root->rightSubtree(local_insert(root->rightSubtree(),v)) : root->leftSubtree(local_insert(root->leftSubtree(),v));

      if( root->value() < v )
          root->rightSubtree( local_insert( root->rightSubtree(), v ) );
      else
            root->leftSubtree( local_insert( root->leftSubtree(), v ) );

    return root;
}

/*
 * insert
 * var in: integer
 * var out:
 * insert passes a TreeNode root and an integer v into local_insert after verifying that v is not anywhere in the TreeNode already using find.
 */
void BinSearchTree::insert(int v)
{
    if( ! find(v) )
        root = local_insert( root, v );
}

/*
 * find
 * var in: integer
 * var out: boolean
 * find passes a TreeNode root and an integer v into local_find and returns the output as an boolean
 */
bool BinSearchTree::find(int v)
{

   return local_find(root, v);
}

/*
 * local_find
 * var in: TreeNode, integer
 * var out: boolean
 * local_find takes a TreeNode root and recursively searches for the integer v
 * Returning true if the integer v matches any of the TreeNode values
 * Returning false if the integer v does not match any of the TreeNode values
 *
 */
bool BinSearchTree::local_find(TreeNode *root, int v)
{
    if(root == nullptr)
        return false;

    if(v == root->value()){
        return true;
    }

   return local_find((root->value() < v ? root->rightSubtree() : root->leftSubtree()),v);
}

/*
 * findParent
 * var in: integer
 * var out: boolean
 * find passes a TreeNode root and an integer v into local_find and returns the output as an boolean
 */
TreeNode* BinSearchTree::findParent(int v)
{
    return BinSearchTree::local_findParent(root, v);
}

/*
 * local_find
 * var in: TreeNode, integer
 * var out: boolean
 * local_find takes a TreeNode root and recursively searches for the integer v
 * Returning true if the integer v matches any of the TreeNode values
 * Returning false if the integer v does not match any of the TreeNode values
 *
 */
TreeNode* BinSearchTree::local_findParent(TreeNode *root, int v)
{
    if(root == nullptr)
        return nullptr;
    if(v == root->value()){
        return root;
    }
    if(v == root->leftSubtree()->value() || v == root->rightSubtree()->value()){
        return root;
    }

    return local_findParent((root->value() < v ? root->rightSubtree() : root->leftSubtree()),v);
}

/*
 *interFind
 * var in:
 * var out: boolean
 * iterFind passes a TreeNode root to the local_literFind and returns the output as a boolean.
 */
bool BinSearchTree::iterFind( int v )
{
    return local_iterFind(root, v);
}

/*
 * local_iterFind
 * var in: TreeNode, Integer
 * var out: boolean
 * local_iterFind searches the TreeNode rote and returns true if the integer v matches any of the TreeNode values
 * returns false if there are no matching TreeNode values.
 */
bool BinSearchTree::local_iterFind(TreeNode *root, int v)
{
   while(root != nullptr){

       if (v == root->value()){
            return true;
        }else
            root = root->value() < v ? root->rightSubtree() : root->leftSubtree();
   }
   return false;
}

/*
 * size
 * var in:
 * var out: integer
 * size passes a TreeNode root to the local_size and returns the output as an integer.
 */
int BinSearchTree::size()
{
    return local_size(root);
}

/*
 * local_size
 * var in: TreeNode
 * var out: integer
 * Local_size takes a TreeNode root and returns the number of nodes withing the tree node as an integer.
 */
int BinSearchTree::local_size(TreeNode *root)
{
    if (root == nullptr)
        return 0;

    return 1 + local_size(root->leftSubtree()) + local_size(root->rightSubtree());
}

/*
 * inorderDump
 * var in:
 * var out:
 * inorderDump passes a TreeNode root to the local_inorderDump for processing.
 */
void BinSearchTree::inorderDump()
{
    local_inorderDump(root);
}

/*
 * local_inorderDump
 * var in: TreeNode
 * var out:
 * Local_InorderDump takes a TreeNode root and parses down to the lowest level and prints each value in ascending order.
 */
void BinSearchTree::local_inorderDump(TreeNode *root)
{
    if(root == nullptr)
        return;

    local_inorderDump(root->leftSubtree());
    std::cout << root->value() << std::endl;
    local_inorderDump(root->rightSubtree());
}

/*
 * maxDepth
 * var in:
 * var out: integer
 * maxDepth passes a TreeNode root to the local_maxDepth and returns the output as an integer.
 */
int  BinSearchTree::maxDepth()
{
    return local_maxDepth(root);
}

/*
 * local_maxDepth
 * var in: TreeNode
 * var out: integer
 * local_maxDepth takes a TreeNode root and returns the longest path as an integer.
 */
int BinSearchTree::local_maxDepth(TreeNode *root)
{
    if(root == nullptr)
        return 0;

    return 1 + std::max(local_maxDepth(root->leftSubtree()),local_maxDepth(root->rightSubtree()));
}

/*
 * levelOrderDump
 * var in:
 * var out:
 * levelOrderDump passes the TreeNode root to local_levelOrderDump for processing.
 */
void BinSearchTree::levelOrderDump(){
    local_levelOrderDump(root);
}

/*
 * local_levelOrderDump
 * var in: TreeNode
 * var out:
 * local_levelOrderDump takes a TreeNode root and prints out each level of the TreeNode from left to right order.
 */
void BinSearchTree::local_levelOrderDump(TreeNode * root)
{
    std::queue<TreeNode *> valuePrintQ;
    std::queue<TreeNode *> trackerQ;

    if(root != nullptr)
    {
        valuePrintQ.push(root);
    }else{
        return;
    }

    for(int i = 0; i < maxDepth(); i++)
    {
        while(!valuePrintQ.empty())
        {
            std::cout << valuePrintQ.front()->value() << std::endl;
           if(valuePrintQ.front()->leftSubtree() != nullptr)
            trackerQ.push(valuePrintQ.front()->leftSubtree());

           if(valuePrintQ.front()->rightSubtree() != nullptr)
            trackerQ.push(valuePrintQ.front()->rightSubtree());

            valuePrintQ.pop();
        }

        while(!trackerQ.empty())
        {
            valuePrintQ.push(trackerQ.front());
            trackerQ.pop();
        }
    }
}

/*
 * remove
 * var in: integer
 * var out: boolean
 * remove passes integer v to local_remove for removal after verifying with find that it is in the TreeNode root.
 * else it returns false.
 */
bool BinSearchTree::remove(int v){
    if(find(v))
    {
        local_remove(root, v);
        return true;
    }else{
        return false;
    }
}

/*
 * local_remove
 * var in: TreeNode, integer
 * var out: TreeNode
 * local_remove finds the integer v value in the TreeNode and then removes it and returns the updated TreeNode to the
 * root BinSearchTree structure.
 */
TreeNode* BinSearchTree::local_remove(TreeNode * root, int v){

        if(root == nullptr)
        {
            return nullptr;
        }

    if(root->value() < v){
        return root->setRightSubtree(local_remove(root->rightSubtree(),v));

    }else if (root->value() > v){
        return root->setLeftSubtree(local_remove(root->leftSubtree(),v));

    }else if(root->value() == v){
            TreeNode * temp = nullptr;

            if(root->leftSubtree() == nullptr && root->rightSubtree() == nullptr){
                delete(root);

            } else if(root->leftSubtree() != nullptr && root->rightSubtree() != nullptr){
                temp = nextLargestValue(root->rightSubtree());
                root->setValue(temp->value());
                local_remove(root->rightSubtree(), temp->value());
                temp = root;

            }else if(root->leftSubtree() != nullptr){
                temp = root->leftSubtree();
                    delete(root);

            }else if(root->rightSubtree() != nullptr){
                 temp = root->rightSubtree();
                    delete(root);

            }
            return temp;
        }
}

/*
 * nextLargestValue
 * var in: TreeNode
 * var out: TreeNode
 *
 */
TreeNode *BinSearchTree::nextLargestValue(TreeNode * root)
{
            if(root->leftSubtree() == nullptr){
                return root;
            }
              return nextLargestValue(root->leftSubtree());
}

/*
 * iterMaxDepth
 * var in:
 * var out: integer
 * iterMaxDepth passes a TreeNode root to the local_iterMaxDepth and returns the output as an integer.
 */
int  BinSearchTree::iterMaxDepth()
{
    return local_maxDepth(root);
}

/*
 * local_iterMaxDepth
 * var in: TreeNode
 * var out: integer
 * local_iterMaxDepth takes a TreeNode root and returns the longest path as an integer iteratively.
 */
int BinSearchTree::local_iterMaxDepth(TreeNode *root)
{
    std::queue<TreeNode *> parentQ;
    std::queue<TreeNode *> childQ;
    int depth = 0;

    if (root != nullptr)
    {
        parentQ.push(root);
        depth++;
    }

    while(!parentQ.empty())
    {
        while (!parentQ.empty())
        {
            if (parentQ.front()->leftSubtree() != nullptr)
                childQ.push(parentQ.front()->leftSubtree());

            if (parentQ.front()->rightSubtree() != nullptr)
                childQ.push(parentQ.front()->rightSubtree());

            parentQ.pop();
        }

        if (!childQ.empty())
        {
            depth++;
        }

        parentQ.swap(childQ);
        childQ.empty();

    }
        return depth;
}

/*
 * kthSmallest
 * var in:
 * var out:
 * kthSmallest takes an integer k and passes it along with the TreeNode root and creates a stack that it
 * passes to local_kthSmallest.
 * it returns the value of the TreeNode root that is passed back from local_kthSmallest.
 */
int BinSearchTree::kthSmallest(int k)
{
    if(local_size(root) < k){
        std::cout << " Return 0 in kthSmallest" << std::endl;
        return 0;
    }
    return local_kthSmallest(root, k);
}

/*
 * local_kthSmallest
 * var in:
 * var out:
 * local_kthSmallest takes a TreeNode root, an integer k and a reference to a stack that is passed by pointer.
 * it returns the TreeNode that is at place K in the stack.
 */

int BinSearchTree::local_kthSmallest(TreeNode * root, int k)
{
std::cout << " TOP" << k << std::endl;
    if(root == nullptr){
        std::cout << " inside root == null" << std::endl;
        return 0;
    }

    if(local_size(root->leftSubtree()) + 1 == k)
        return root->value();

    if(local_size(root->leftSubtree()) + 1 < k)
        return local_kthSmallest(root->rightSubtree(), (k - (local_size(root->leftSubtree()) + 1)));

    if(local_size(root->leftSubtree()) + 1 > k)
        return local_kthSmallest(root->leftSubtree(), k);

}


void BinSearchTree::valuesAtlevel(int k){
    local_valuesAtLevel(root, k);
}

void BinSearchTree::local_valuesAtLevel(TreeNode * root, int k){
        if(root == nullptr)
            return;

        local_valuesAtLevel(root->leftSubtree(), k -1);
        if(k == 1){
            std::cout << root->value() << " ";
        }
        local_valuesAtLevel(root->rightSubtree(), k -1);
}

void BinSearchTree::iterValuesAtLevel(int k){
    local_iterValuesAtLevel(root, k);

}
void BinSearchTree::local_iterValuesAtLevel(TreeNode * root, int k){

    std::queue<TreeNode *> lastLevelQ;
    std::queue<TreeNode *> nextLevelQ;

    if (root != nullptr)
    {
        lastLevelQ.push(root);
        k = k - 1;
    }

    while(k >= 1)
    {
        while (!lastLevelQ.empty())
        {
            if (lastLevelQ.front()->leftSubtree() != nullptr)
                nextLevelQ.push(lastLevelQ.front()->leftSubtree());

            if (lastLevelQ.front()->rightSubtree() != nullptr)
                nextLevelQ.push(lastLevelQ.front()->rightSubtree());

            lastLevelQ.pop();
        }
        k = k - 1;
        lastLevelQ.swap(nextLevelQ);
        nextLevelQ.empty();
    }
    while(!lastLevelQ.empty()){
        std::cout << lastLevelQ.front()->value() << " ";
        lastLevelQ.pop();
    }
}

bool BinSearchTree::hasRootToLeafSum(int sum){
    return local_hasRootToLeafSum(root, sum);

}

bool BinSearchTree::local_hasRootToLeafSum(TreeNode * root, int sum){

    if(root == nullptr){
        return false;
    }

    sum = sum - root->value();

    if(sum == 0){
        if(root->leftSubtree() == nullptr && root->rightSubtree() == nullptr){
            return true;
        }
    }

 return  local_hasRootToLeafSum(root->leftSubtree(), (sum) )|| local_hasRootToLeafSum(root->rightSubtree(), (sum));
}

bool BinSearchTree::areIdentical(BinSearchTree *bst){
        return local_areIdentical(root, bst->root);
}

bool BinSearchTree::local_areIdentical(TreeNode * root, TreeNode * bstRoot){

    if(root == nullptr && bstRoot == nullptr){
            return true;
    }

    if(root != nullptr && bstRoot != nullptr){
        return local_areIdentical(root->leftSubtree(), bstRoot->leftSubtree()) && local_areIdentical(root->rightSubtree(), bstRoot->rightSubtree());
    }
        return false;
}

BinSearchTree *BinSearchTree::intersectWith(BinSearchTree *bst){
    BinSearchTree *resultBST = new BinSearchTree();
    resultBST->root = nullptr;
   local_intersectWith(root, root, bst->root, bst->root, resultBST);
    return resultBST;

}

void *BinSearchTree::local_intersectWith(TreeNode * root, TreeNode *rootTop, TreeNode * bstRoot, TreeNode * bstRootTop, BinSearchTree *resultBST){ // I hate this, try to figure out how to not send in root and bst root twice
    if(root == nullptr || bstRoot == nullptr){
        return nullptr;
    }

    if(local_find(bstRootTop, root->value())){
            resultBST->insert(root->value());
    }
    if(local_find(rootTop, bstRoot->value())){
            //not in result tree thus insert
            resultBST->insert(bstRoot->value());
    }
local_intersectWith(root->leftSubtree(), root, bstRoot->leftSubtree(),bstRoot, resultBST);
local_intersectWith(root->rightSubtree(), root, bstRoot->rightSubtree(), bstRoot, resultBST);
}


BinSearchTree *BinSearchTree::unionWith(BinSearchTree *bst){
    BinSearchTree *resultBST = new BinSearchTree();
    resultBST->root = nullptr;
    local_unionWith(root, resultBST);
    local_unionWith(bst->root, resultBST);
    return resultBST;

}

void BinSearchTree::local_unionWith(TreeNode * root, BinSearchTree *resultBST){ // I hate this, try to figure out how to not send in root and bst root twice
    if(root != nullptr){
        resultBST->insert(root->value());
        local_unionWith(root->leftSubtree(), resultBST);
        local_unionWith(root->rightSubtree(), resultBST);
    }
}




BinSearchTree::~BinSearchTree(){
    deleteBinSearchTree(root);
};

void BinSearchTree::deleteBinSearchTree(TreeNode * root){
    if(root != nullptr) {
        deleteBinSearchTree(root->leftSubtree());
        deleteBinSearchTree(root->rightSubtree());
        delete root;
    }
}