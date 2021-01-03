/*
 * @lc app=leetcode.cn id=654 lang=cpp
 *
 * [654] 最大二叉树
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

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
class Solution {
public:
    TreeNode *constructMaximumBinaryTree(vector<int> &nums)
    {
        return buildTree(nums, 0, nums.size() - 1);
    }

private:
    TreeNode *buildTree(vector<int> &nums, int start, int end)
    {
        if (start > end) {
            return NULL;
        }
        auto max_pos = max_element(nums.begin() + start, nums.begin() + end + 1);
        TreeNode *root = new TreeNode(*max_pos);
        root->left = buildTree(nums, start, max_pos - nums.begin() - 1);
        root->right = buildTree(nums, max_pos - nums.begin() + 1, end);
        return root;
    }
};
// @lc code=end

void pre_order_traverse(TreeNode *node)
{
    if (node == NULL) {
        return;
    }
    cout << node->val << " ";
    pre_order_traverse(node->left);
    pre_order_traverse(node->right);
}

void level_order_traverse(TreeNode *node)
{
    queue<TreeNode *> qe;
    qe.push(node);
    while (!qe.empty()) {
        TreeNode *cur = qe.front();
        qe.pop();
        if (cur == NULL) continue;
        cout << cur->val << " ";
        qe.push(cur->left);
        qe.push(cur->right);
    }
}


int main()
{
    Solution sol;
    vector<int> nums{3, 2, 1, 6, 0, 5};
    TreeNode *root = sol.constructMaximumBinaryTree(nums);
    level_order_traverse(root);
    return 0;
}

