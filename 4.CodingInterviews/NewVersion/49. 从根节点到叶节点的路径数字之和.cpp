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
    int ans{0};

   public:
    int sumNumbers(TreeNode* root) {
        if (!root)
            return 0;
        calc(root, 0);
        return ans;
    }

   private:
    /* node must not be nullptr */
    void calc(TreeNode* node, int num) {
        assert(node);
        if (!node->left && !node->right) {
            ans += num * 10 + node->val;
            return;
        }
        if (node->left) {
            calc(node->left, num * 10 + node->val);
        }
        if (node->right) {
            calc(node->right, num * 10 + node->val);
        }
    }
};

int main() {
    return 0;
}