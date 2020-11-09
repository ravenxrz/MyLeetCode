/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
 */
#include <iostream>
#include <vector>
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

    // vals 中的元素 pair <int, bool> int代表值， bool代表是否是左分支
    bool isValid(TreeNode *node, vector<pair<int,bool>> vals){
        if(node == nullptr)
            return true;

        const int my_val = node->val;
        for(auto _pair : vals){
            if(_pair.second){   // 左分支
                if(my_val >= _pair.first){
                    return false;
                }
            }else{
                if(my_val <= _pair.first){
                    return false;
                }
            }
        }

        vals.emplace_back(my_val,true);
        // left sub-tree
        if(!isValid(node->left,vals))
            return false;
        vals.pop_back();
        vals.emplace_back(my_val,false);
        // right sub-tree
        return isValid(node->right, vals);
    }

    bool isValidBST(TreeNode* root) {
        vector<pair<int,bool>> vec;
        return isValid(root,vec);
    }
};
// @lc code=end

int main()
{
    Solution sol;
    TreeNode *node1 = new TreeNode(10);
    TreeNode *node2 = new TreeNode(5);
    TreeNode *node3 = new TreeNode(15);
    TreeNode *node4 = new TreeNode(6);
    TreeNode *node5 = new TreeNode(20);
    node1->left = node2;
    node1->right = node3;
    node3->left = node4;
    node3->right = node5;
    cout << sol.isValidBST(node1);

    return 0;
}