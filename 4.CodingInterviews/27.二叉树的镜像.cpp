#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode *mirrorTree(TreeNode *root)
    {
        inorder_mirror(root) ;
        return root;
    }

private:
    void inorder_mirror(TreeNode *node)
    {
        if (node == NULL) return;
        // traverse
        inorder_mirror(node->left);
        inorder_mirror(node->right);
        // swap left and right child
        TreeNode *tmp = node->left;
        node->left = node->right;
        node->right = tmp;
    }
};

void print_tree_inorder(TreeNode *node){
    if(node == NULL)  return;
    cout << node->val << '\n';
    print_tree_inorder(node->left);
    print_tree_inorder(node->right);
}

int main()
{
    Solution sol;
    TreeNode *root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    
    sol.mirrorTree(root);
    print_tree_inorder(root);
    return 0;
}
