//
// Created by Raven on 2021/2/5.
//
#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
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
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        if (root == NULL) return {};
        
        vector<vector<int>> ans;
        stack<TreeNode *> stk1;
        stack<TreeNode *> stk2;
        stk1.push(root);
        int level = 1;
        
        while (!stk1.empty() || !stk2.empty()) {
            vector<int> tmp;
            if (level & 1) {      // 奇数层
                // read from stk1
                while (!stk1.empty()) {
                    TreeNode *cur = stk1.top();
                    stk1.pop();
                    if (cur == NULL) continue;
                    tmp.push_back(cur->val);
                    // push children
                    stk2.push(cur->left);
                    stk2.push(cur->right);
                }
            } else {               // 偶数层
                // read from stk2
                while (!stk2.empty()) {
                    TreeNode *cur = stk2.top();
                    stk2.pop();
                    if (cur == NULL) continue;
                    tmp.push_back(cur->val);
                    // push children
                    stk1.push(cur->right);
                    stk1.push(cur->left);
                }
            }
            level++;
            if (!tmp.empty()) ans.emplace_back(tmp);
        }
        return ans;
    }
};
