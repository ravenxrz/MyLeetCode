//
// Created by Raven on 2021/3/13.
//
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
    int rob(TreeNode *root)
    {
        if (root == nullptr) return 0;
        auto ret = rob_core(root);
        return max(ret[0], ret[1]);
    }

private:
    vector<int> rob_core(TreeNode *node)
    {
        if (node == nullptr) return {0, 0};
        
        vector<int> left = rob_core(node->left);
        vector<int> right = rob_core(node->right);
        
        int do_rob = node->val + left[0] + right[0];
        int not_do_rob = max(left[0], left[1]) + max(right[0], right[1]);
        return {not_do_rob, do_rob};
    }
};

int main()
{
    Solution sol;
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(4);
    root->right = new TreeNode(5);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->right = new TreeNode(1);
    cout << sol.rob(root) << endl;
    return 0;
}
