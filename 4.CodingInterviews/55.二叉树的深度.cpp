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
    int maxDepth(TreeNode* root) {
        return height(root);
    }
private:
    int height(TreeNode *node){
        if(node == NULL) return 0;
        return max(height(node->left),height(node->right)) + 1;
    }
};
