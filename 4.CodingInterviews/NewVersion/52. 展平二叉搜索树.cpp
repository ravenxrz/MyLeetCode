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
    TreeNode* increasingBST(TreeNode* node) {
        if (!node)
            return nullptr;
        TreeNode* left = increasingBST(node->left);
        TreeNode* right = increasingBST(node->right);
        /* clean left pointer */
        node->left = nullptr;
        /* connect right sub tree */
        node->right = right;
        /* connect left sub tree */
        TreeNode* oleft = left; /* save left pointer to return later */
        TreeNode* pleft = left;
        while (left) {
            pleft = left;
            left = left->right;
        }
        if (pleft) {
            pleft->right = node;
        }
        /* return new root node pointer */
        return oleft ? oleft : node;
    }
};

int main() {
    return 0;
}