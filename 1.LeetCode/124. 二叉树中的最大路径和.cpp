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
    int max_val;

   public:
    int maxPathSum(TreeNode* root) {
        max_val = INT32_MIN;
        pathSum(root);
        return max_val;
    }

   private:
    int pathSum(TreeNode* node) {
        if (node == nullptr)
            return 0;
        int left = max(pathSum(node->left), 0);
        int right = max(pathSum(node->right), 0);

        int val = left + right + node->val;
        max_val = max(max_val, val);
        return max(left, right) + node->val;
    }
};

int main() {
    TreeNode* node = nullptr;
    createTree(&node);
    Solution sol;
    cout << sol.maxPathSum(node) << endl;
    return 0;
}