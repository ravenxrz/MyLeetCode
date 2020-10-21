/*
 * @lc app=leetcode.cn id=112 lang=cpp
 *
 * [112] 路径总和
 */
#include <iostream>
#include <cstdio>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x)
        : val(x)
        , left(NULL)
        , right(NULL)
    {
    }
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

    bool pre_order_traverse(TreeNode *t, int counter, int sum){
        if(t == NULL)
            return false;
        
        counter += t->val;
        if(t->left == NULL&& t->right == NULL) // 叶子节点
        {
            if(counter == sum)
                return true;
            else
                return false;
        }
            
        if(pre_order_traverse(t->left, counter, sum)){
            return true;
        }
        return pre_order_traverse(t->right, counter, sum);
    }

    bool hasPathSum(TreeNode* root, int sum)
    {
        return pre_order_traverse(root, 0, sum);
    }
};
// @lc code=end
