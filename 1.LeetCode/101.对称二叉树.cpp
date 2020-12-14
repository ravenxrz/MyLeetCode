/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
 */
#include <vector>
#include <queue>
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
    
    bool check(TreeNode *left, TreeNode *right)
    {
        if ((left != nullptr && right == nullptr) ||
            (left == nullptr) && right != nullptr)
            return false;
        
        if (left == nullptr && right == nullptr) return true;
        
        if (left->val != right->val) return false;
        
        // 递归check
        if (!check(left->left, right->right)) {
            return false;
        }
        
        return check(left->right, right->left);
    }
    
    
    bool isSymmetric(TreeNode *root)
    {
        if(root == nullptr) return true;
        return check(root->left,root->right);
    }
};
// @lc code=end

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);
    Solution sol;
    cout << sol.isSymmetric(root);
    return 0;
}