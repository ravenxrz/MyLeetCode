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
        memo.clear();
        return rob_core(root);
    }

private:
    int rob_core(TreeNode *node)
    {
        if (node == nullptr) return 0;
        if (memo.count(node)) return memo[node];
        
        int base1 = node->val +
                    (node->left ? rob_core(node->left->left) + rob_core(node->left->right) : 0) +
                    (node->right ? rob_core(node->right->left) + rob_core(node->right->right) : 0);
        int base2 = rob_core(node->left) + rob_core(node->right);
        memo[node] = max(base1, base2);
        return memo[node];
    }

private:
    unordered_map<TreeNode *, int> memo;
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
