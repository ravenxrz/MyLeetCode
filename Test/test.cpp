/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层序遍历
 */
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}// @lc code=start
};

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        if (root == nullptr) return {};
        
        // insert root
        vector<vector<int>> ans;
        
        queue<pair<TreeNode *, int>> qe;
        qe.push({root, 0});
        while (!qe.empty()) {
            auto node = qe.front();
            qe.pop();
            
            if (ans.size() <= node.second) {
                ans.push_back({node.first->val});
            } else {
                ans[node.second].push_back(node.first->val);
            }
            
            if (node.first->left != nullptr) {
                qe.push({node.first->left, node.second + 1});
            }
            if (node.first->right != nullptr) {
                qe.push({node.first->right, node.second + 1});
            }
            
        }
        return ans;
    }
};
// @lc code=end

int main()
{
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    Solution sol;
    const vector<vector<int>> &ans = sol.levelOrder(root);
    for (const auto &level : ans) {
        for (const auto &val : level) {
            cout << val << endl;
        }
    }
    return 0;
}
