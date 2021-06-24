#include "leetcode_base.h"

/*
 * @lc app=leetcode.cn id=623 lang=cpp
 *
 * [623] 在二叉树中增加一行
 */

// @lc code=start
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
class Solution
{
private:
    int target_depth;
    int target_val;

public:
    TreeNode *addOneRow(TreeNode *root, int val, int depth)
    {
        if (depth == 1)
        {
            TreeNode *new_root = new TreeNode(val);
            new_root->left = root;
            return new_root;
        }
        else
        {
            target_depth = depth;
            target_val = val;
            process(root, 1);
            return root;
        }
    }

private:
    void process(TreeNode *node, int cur_level)
    {
        if (node == nullptr)
            return;
        if (cur_level >= target_depth)
            return;

        if (cur_level == target_depth - 1)
        {
            TreeNode *node1 = new TreeNode(target_val);
            TreeNode *node2 = new TreeNode(target_val);
            node1->left = node->left;
            node2->right = node->right;
            node->left = node1;
            node->right = node2;
            return;
        }
        process(node->left, cur_level + 1);
        process(node->right, cur_level + 1);
    }
};
// @lc code=end

int main()
{
    return 0;
}