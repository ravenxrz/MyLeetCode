#include "leetcode_base.h"

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
    bool balance_;

   public:
    bool isBalanced(TreeNode* root) {
        balance_ = true;
        getHeight(root);
        return balance_;
    }

   private:
    int getHeight(TreeNode* node) {
        if (node == nullptr)
            return 0;
        if (!balance_)
            return 0;
        int left = getHeight(node->left);
        int right = getHeight(node->right);
        if (std::abs(left - right) > 1) {
            balance_ = false;
            return 0;
        }
        return max(left, right) + 1;
    }
};

int main() {
    Solution sol;
    TreeNode* node = nullptr;
    createTree(&node);
    cout << sol.isBalanced(node) << endl;
    return 0;
}