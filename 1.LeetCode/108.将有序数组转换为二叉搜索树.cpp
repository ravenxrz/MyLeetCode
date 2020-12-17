/*
 * @lc app=leetcode.cn id=108 lang=cpp
 *
 * [108] 将有序数组转换为二叉搜索树
 */
#include <bits/stdc++.h>
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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return build(nums,0,nums.size()-1);
    }
private:
    TreeNode* build(vector<int>& nums, int start, int end){
        if(start > end) return nullptr;
        if(start == end)  return new TreeNode(nums.at(start));
        int mid = (start+end)/2;
        TreeNode* midNode = new TreeNode(nums.at(mid));
        midNode->left = build(nums,start,mid-1);
        midNode->right = build(nums,mid+1,end);
        return midNode;
    }
};
// @lc code=end

