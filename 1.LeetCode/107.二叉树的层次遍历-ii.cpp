/*
 * @lc app=leetcode.cn id=107 lang=cpp
 *
 * [107] 二叉树的层次遍历 II
 */
#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// @lc code=start
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
    vector<vector<int>> levelOrderBottom(TreeNode *root)
    {
        if (root == nullptr) return {};
        
        vector<vector<int>> ans;
        queue<pair<TreeNode *, int>> qe;
        qe.push({root, 0});
        while (!qe.empty()) {
            auto cur = qe.front();
            qe.pop();
            if (cur.first == nullptr) continue;
            
            if (ans.size() == cur.second) {
                ans.push_back({cur.first->val});
            } else {
                ans[cur.second].push_back(cur.first->val);
            }
            // push child node
            qe.push({cur.first->left, cur.second + 1});
            qe.push({cur.first->right, cur.second + 1});
        }
        // reverse
        reverse(ans.begin(),ans.end());
        return ans; 
    }
};
// @lc code=end

