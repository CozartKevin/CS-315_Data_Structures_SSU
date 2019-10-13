//
// Created by Kevin on 10/8/2019.
//
#include <iostream>
#include <algorithm>
#include <queue>
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

bool BinSearchTree::remove(int v){

    if(local_remove(root,v) == nullptr){
        return false;
    }else{
        return true;
    }

}

TreeNode* BinSearchTree::local_remove(TreeNode * root, int v){

        if(root == nullptr)
        {
            return nullptr;
        }

        if(root->value() == v){
            TreeNode * parentRoot = findParent(v);
            TreeNode * temp = nullptr;
            if(root->leftSubtree() == nullptr && root->rightSubtree() == nullptr){
                free(root);
            } else if(root->leftSubtree() != nullptr && root->rightSubtree() != nullptr){
                temp = nextLargestValue(root->rightSubtree());
                root->value() = temp->value();
                local_remove(root->rightSubtree(), temp->value());
                temp = root;


            }else if(root->leftSubtree() != nullptr){
                temp = root->leftSubtree();
                    free(root);

            }else if(root->rightSubtree() != nullptr){
                 temp = root->rightSubtree();
                    free(root);
            }
            return temp;
        }
        if(root->value() < v){
           TreeNode *right = local_remove(root->rightSubtree(),v);
            return root->setRightSubtree(right);
        }else if (root->value() > v){
            TreeNode *left = local_remove(root->leftSubtree(),v);
            return root->setLeftSubtree(left);
        }




        /*
         TreeNode * parentNode = local_findParent(root, v);
        if(parentNode == nullptr){
                return false;
        }
         if(parentNode->value() == v){
            if(parentNode->rightSubtree()->leftSubtree() == nullptr){
                parentNode->leftSubtree(parentNode->rightSubtree());
            }
            else if(parentNode->leftSubtree()->rightSubtree() == nullptr)
            {
                parentNode->rightSubtree((parentNode->leftSubtree());
            }

         }else if( parentNode->leftSubtree()->value() == v){

             parentNode->leftSubtree()->rightSubtree()->leftSubtree(parentNode->leftSubtree()->leftSubtree());
             parentNode->leftSubtree(parentNode->leftSubtree()->rightSubtree());

         }else if(parentNode ->rightSubtree()->value() == v){
            parentNode->rightSubtree()->leftSubtree()->rightSubtree(parentNode->rightSubtree()->rightSubtree());
            parentNode->rightSubtree(parentNode->rightSubtree()->leftSubtree());

         }
            //remove then

            return true;
         */
}


TreeNode *BinSearchTree::nextLargestValue(TreeNode * root)
{
            if(root->leftSubtree() == nullptr){
                return root;
            }
              return nextLargestValue(root->leftSubtree());
}

