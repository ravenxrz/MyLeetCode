/*
 * @lc app=leetcode.cn id=222 lang=cpp
 *
 * [222] 完全二叉树的节点个数
 */
#include <iostream>
#include <algorithm>

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
    int countNodes(TreeNode *root)
    {
        if (root == NULL) return 0;
        return _countNodes(root, 1);
    }

private:
    int _countNodes(TreeNode *node, int num)
    {
        if (node == NULL) return num >> 1;
        return max(_countNodes(node->right, num << 1 | 1), _countNodes(node->left, num << 1));
    }
};
// @lc code=end

