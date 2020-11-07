/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    void _inorder_traversal(TreeNode *node, vector<int> &inorder){
        if(node == nullptr) return;
        _inorder_traversal(node->left,inorder);
        inorder.push_back(node->val);
        _inorder_traversal(node->right,inorder);
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inorder;
        _inorder_traversal(root,inorder);
        return inorder;
    }
};
// @lc code=end

