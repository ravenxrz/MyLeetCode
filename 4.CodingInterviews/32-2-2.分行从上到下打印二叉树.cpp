//
// Created by Raven on 2021/2/5.
//
#include <iostream>
#include <vector>
#include <queue>

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
        // empty check
        if (root == NULL) return {};
        
        vector<vector<int>> ans;
        ans.resize(1);
        queue<TreeNode *> qe;
        qe.push(root);
        int toBePrint = 1;
        int nextLevelNum = 0;
        int level = 0;
        while (!qe.empty()) {
            TreeNode *cur = qe.front();
            ans[level].push_back(cur->val);
            
            toBePrint--;
            // push non-null children
            if (cur->left != NULL) {
                nextLevelNum++;
                qe.push(cur->left);
            }
            if (cur->right != NULL) {
                nextLevelNum++;
                qe.push(cur->right);
            }
            if (toBePrint == 0) {
                toBePrint = nextLevelNum;
                nextLevelNum = 0;
                level++;
                ans.resize(level);
            }
        }
        return ans;
    }
};