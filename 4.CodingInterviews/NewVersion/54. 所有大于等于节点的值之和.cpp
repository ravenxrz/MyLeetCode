#include "leetcode_base.h"

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
   public:
    TreeNode* convertBST(TreeNode* root) {
        convert(root, 0);
        return root;
    }

    int convert(TreeNode* node, int base) {
        if(!node) return 0;
        int rvalue = convert(node->right, base);
        /* update current node's value */
        int cur_node_value = node->val;
        node->val += base + rvalue;
        int lvalue = convert(node->left, node->val);
        return cur_node_value + rvalue + lvalue;
    }
};

