#include "leetcode_base.h"

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
    vector<vector<int>> ans;
public:
    vector<vector<int>> pathSum(TreeNode *root, int target)
    {
        ans.clear();
        vector<int> tmp_ans;
        getAns(root, tmp_ans, target);
        return ans;
    }

private:
    void getAns(TreeNode *node, vector<int> &tmp_ans, int target)
    {
        if (node == nullptr) return;
        if (node->left == nullptr && node->right == nullptr) {
            tmp_ans.push_back(node->val);
            if (accumulate(tmp_ans.begin(), tmp_ans.end(), 0) == target) {
                ans.push_back(tmp_ans);
            }
            tmp_ans.pop_back();
            return;
        }
        tmp_ans.push_back(node->val);
        // go left
        getAns(node->left, tmp_ans, target);
        // go right
        getAns(node->right, tmp_ans, target);
        tmp_ans.pop_back();
    }
};


int main()
{
    Solution sol;
    TreeNode *node;
    createTree(&node);
    for (auto &vec : sol.pathSum(node, 22)) {
        for (auto val : vec) {
            cout << val << ' ';
        }
        cout << endl;
    }
    return 0;
}
