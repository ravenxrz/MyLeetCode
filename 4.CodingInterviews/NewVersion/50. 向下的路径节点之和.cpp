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
    unordered_map<int, int> prefix_sum;

   public:
    int pathSum(TreeNode* root, int targetSum) {
        ans = 0;
        prefix_sum.clear();
        prefix_sum[0] = 1;
        calc(root, 0, targetSum);
        return ans;
    }

   private:
    void calc(TreeNode* node, int base, int targetSum) {
        if (node == nullptr)
            return;
        int sum = node->val + base;
        if (prefix_sum.count(sum - targetSum)) {
            ans += prefix_sum[sum - targetSum];
        }
        prefix_sum[sum]++;
        calc(node->left, sum, targetSum);
        calc(node->right, sum, targetSum);
        prefix_sum[sum]--;
    }
};

int main() {
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->right = new TreeNode(3);
    root->right->right->right = new TreeNode(4);
    root->right->right->right->right = new TreeNode(4);
    Solution sol;
    cout << sol.pathSum(root, 3) << endl;
    return 0;
}