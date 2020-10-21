/*
 * @lc app=leetcode.cn id=113 lang=cpp
 *
 * [113] 路径总和 II
 */
#include <iostream>
#include <cstdio>
#include <vector>
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
    vector<vector<int>> ans;

    void pre_order_traverse(TreeNode* t, int counter, int sum, vector<int> tmp)
    {
        if(t == NULL)
            return ;
        
        // put
        tmp.push_back(t->val);
        counter += t->val;
        if(t->left == NULL&& t->right == NULL) // 叶子节点
        {
            if(counter == sum){
                ans.push_back(tmp);
                return ;
            }else{
                // remove
                tmp.pop_back();
                return ;
            }   
        }

        pre_order_traverse(t->left, counter, sum, tmp);
        pre_order_traverse(t->right, counter, sum, tmp);
    }

    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        pre_order_traverse(root, 0, sum, {});
        return ans;
    }

};
// @lc code=end

