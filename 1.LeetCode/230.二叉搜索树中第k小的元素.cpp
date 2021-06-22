#include "leetcode_base.h"
/*
 * @lc app=leetcode.cn id=230 lang=cpp
 *
 * [230] 二叉搜索树中第K小的元素
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
    int target_order;
    int cur_order;
    int ans;

public:
    int kthSmallest(TreeNode *root, int k)
    {
        ans = -1;
        target_order = k;
        cur_order = 1;
        postOrderTraverse(root);
        return ans;
    }

private:
    void postOrderTraverse(TreeNode *node)
    {
        if (node == nullptr)
        {
            return;
        }
        postOrderTraverse(node->left);
        // Take
        if (cur_order++ == target_order)
        {
            ans = node->val;
            return;
        }
        postOrderTraverse(node->right);
    }
};
// @lc code=end

int main()
{
    Solution sol;
    {
        TreeNode *root = nullptr;
        createTree(&root);
        for (int i = 1; i <= 4; i++)
        {
            cout << sol.kthSmallest(root, i) << endl;
        }
    }
    return 0;
}