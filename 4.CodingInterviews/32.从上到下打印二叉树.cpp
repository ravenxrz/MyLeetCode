#include <iostream>
#include <queue>
#include <vector>

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
    vector<int> levelOrder(TreeNode *root)
    {
        if (root == NULL) return {};
        
        vector<int> ans;
        queue<TreeNode *> qu;
        qu.push(root);
        while (!qu.empty()) {
            TreeNode *cur = qu.front();
            qu.pop();
            if (cur == NULL) continue;
            ans.push_back(cur->val);
            qu.push(cur->left);
            qu.push(cur->right);
        }
        return ans;
    }
};
