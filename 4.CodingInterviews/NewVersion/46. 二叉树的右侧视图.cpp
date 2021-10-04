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
    vector<int> rightSideView(TreeNode* root) {
        if (!root)
            return {};

        vector<int> ans;
        queue<TreeNode*> qe;
        int cur_level_nums = 1;
        int next_level_nums = 0;

        qe.push(root);

        while (!qe.empty()) {
            TreeNode* node = qe.front();
            qe.pop();
            cur_level_nums--;
            if (node->left) {
                qe.push(node->left);
                next_level_nums++;
            }
            if (node->right) {
                qe.push(node->right);
                next_level_nums++;
            }
            if (cur_level_nums == 0) {
                cur_level_nums = next_level_nums;
                next_level_nums = 0;
                ans.push_back(node->val);
            }
        }
        return ans;
    }
};

int main() {}