
#ifndef _TreeNode
#define _TreeNode

class TreeNode {
public:
    TreeNode(): left(nullptr), right(nullptr), data(0) {} 
    TreeNode( int n ): left(nullptr), right(nullptr), data(n) {} 

    TreeNode *leftSubtree() { return left; }
    TreeNode *rightSubtree() { return right; }

    void leftSubtree( TreeNode *left ) { this->left = left; }
    void rightSubtree(TreeNode *right) { this->right = right; }

    TreeNode *setLeftSubtree(TreeNode *temp) {this->left = temp; return this;} //sets left subtree and returns the node
    TreeNode *setRightSubtree(TreeNode * temp){ this->right = temp; return this;} //sets right subtree and returns the node

    int& value() { return data; }
    int& setValue(int v) { data = v; return data; }



private:
    TreeNode *left, *right;
    int data;
};  

#endif
