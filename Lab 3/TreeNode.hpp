
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

    TreeNode *setLeftSubtree(TreeNode *temp) {this->left = temp; return left;}
    TreeNode *setRightSubtree(TreeNode * temp){ this->right = temp; return right;}

    int& value() { return data; } 

private:
    TreeNode *left, *right;
    int data;
};  

#endif
