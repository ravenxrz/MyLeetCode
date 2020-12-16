/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] 从中序与后序遍历序列构造二叉树
 */
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    
    TreeNode(int x)
            : val(x), left(NULL), right(NULL)
    {
    }
};

/**
 * 中序遍历 inorder = [9,3,15,20,7]
 * 后序遍历 postorder = [9,15,7,20,3]
 */

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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        post_idx = inorder.size() - 1;
        for (int i = 0; i < inorder.size(); i++) {
            in_map[inorder.at(i)] = i;
        }
        
        return build(inorder, 0, inorder.size() - 1, postorder);
    }
    
    TreeNode *build(vector<int> &inorder, int start, int end, vector<int> &postorder)
    {
        if (start > end)
            return nullptr;
        if (start == end) {
            post_idx--;
            return new TreeNode(inorder[start]);
        }
        
        TreeNode *midNode = new TreeNode(postorder[post_idx--]);
        int midIdx = in_map[midNode->val];
        midNode->right = build(inorder, midIdx + 1, end, postorder);
        midNode->left = build(inorder, start, midIdx - 1, postorder);
        return midNode;
    }

private:
    int post_idx;
    map<int, int> in_map;
};
// @lc code=end

int main()
{
    Solution sol;
    vector<int> in{9,3,15,20,7};
    vector<int> post{9,15,7,20,3};
    sol.buildTree(in, post);
    return 0;
}
