//
// Created by Kevin on 10/8/2019.
//
#include <iostream>
#include "TreeNode.hpp"
#include "BinSearchTree.hpp"

 TreeNode *BinSearchTree::local_insert( TreeNode *root, int v ) {
    if( root == nullptr )
        return new TreeNode( v );
    if( root->value() < v )
        root->rightSubtree( local_insert( root->rightSubtree(), v ) );
    else
        root->leftSubtree( local_insert( root->leftSubtree(), v ) );
    return root;
}

void BinSearchTree::insert(int v) {
    if( ! find(v) )
        root = local_insert( root, v );
}





bool BinSearchTree::find(int v) {
   return BinSearchTree::find(root, v);
}

bool BinSearchTree::find( TreeNode * root, int v){
    if(root == nullptr)
        return false;

    if(v == root->value()){
        return true;
    }else if(v > root->value()){
        return find(root->rightSubtree(),v);
    }else{
        return find(root->leftSubtree(), v);
    }


}


bool BinSearchTree::iterFind( int v ){
return false;
}
void BinSearchTree::inorderDump(){
std::cout << "Inside in order dump" << std::endl;

}
int  BinSearchTree::maxDepth(){


return 0;
}
