#include <bits/stdc++.h>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

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
public:
    int minDepth(TreeNode *root)
    {
        if (root == nullptr) return 0;
        queue<TreeNode *> qe;
        int min_level = 1;
        qe.push(root);
        
        while (!qe.empty()) {
            int sz = qe.size();
            for (int i = 0; i < sz; i++) {
                TreeNode *node = qe.front();
                qe.pop();
                
                if (!node->left && !node->right) {
                    return min_level;
                }
                
                // push next level
                if (node->left) qe.push(node->left);
                if (node->right) qe.push(node->right);
            }
            min_level++;
        }
        
        return -1;
    }
};
