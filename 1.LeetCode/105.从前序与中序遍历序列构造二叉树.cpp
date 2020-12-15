/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
 */

#include <vector>
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
    
    TreeNode *build(vector<int> &preorder, int &pre_idx, vector<int> &inorder, int start, int end)
    {
        if (start > end) {
            return nullptr;
        }
        if (start == end) {
            pre_idx++;
            return new TreeNode(inorder.at(start));
        }
        
        int cur_val = preorder.at(pre_idx++);
        int cur_val_pos = find(inorder.begin(), inorder.end(), cur_val) - inorder.begin();
    
        TreeNode *cur_node = new TreeNode(cur_val);
        cur_node->left = build(preorder, pre_idx, inorder, start, cur_val_pos - 1);
        cur_node->right = build(preorder, pre_idx, inorder, cur_val_pos + 1, end);
        return cur_node;
    }
    
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        int pre_idx = 0;
        return build(preorder, pre_idx, inorder, 0, inorder.size() - 1);
    }
};
// @lc code=end


int main()
{
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};;
    Solution sol;
    sol.buildTree(preorder,inorder);
    return 0;
}