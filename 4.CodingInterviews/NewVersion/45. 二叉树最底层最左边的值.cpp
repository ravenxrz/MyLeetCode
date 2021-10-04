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
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> qe;
        int ans = -1;
        int cur_level_nums = 1, next_level_nums = 0;

        qe.push(root);
        ans = root->val;

        while (!qe.empty()) {
            TreeNode* cur = qe.front();
            qe.pop();
            cur_level_nums--;
            if (cur->left) {
                qe.push(cur->left);
                next_level_nums++;
            }
            if (cur->right) {
                qe.push(cur->right);
                next_level_nums++;
            }
            if (cur_level_nums == 0) {
                cur_level_nums = next_level_nums;
                next_level_nums = 0;
                if (!qe.empty()) {
                    ans = qe.front()->val;
                }
            }
        }
        return ans;
    }
};

int main() {
    return 0;
}