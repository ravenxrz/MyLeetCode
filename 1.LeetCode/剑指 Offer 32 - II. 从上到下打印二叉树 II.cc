//
// Created by Raven on 2021/7/24.
//

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == nullptr)
            return {};

        vector<vector<int>> ans;
        queue<TreeNode*> qe;
        int cur_level_num = 0;
        int next_level_num = 0;
        int cur_level = 0;
        // init state
        qe.push(root);
        cur_level_num = 1;

        while (!qe.empty()) {
            auto cur_node = qe.front();
            qe.pop();
            cur_level_num--;
            if (ans.size() == cur_level) {
                ans.push_back({cur_node->val});
            } else {
                ans.back().push_back(cur_node->val);
            }

            if (cur_node->left) {
                next_level_num++;
                qe.push(cur_node->left);
            }
            if (cur_node->right) {
                next_level_num++;
                qe.push(cur_node->right);
            }

            if (cur_level_num == 0) {
                cur_level_num = next_level_num;
                next_level_num = 0;
                cur_level++;
            }
        }
        return ans;
    }
};
