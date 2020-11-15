/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
 */

#include <vector>
#include <stack>
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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<pair<TreeNode *, int>> stk;
        stk.push({root, 0});

        while (!stk.empty()) {
            struct TreeNode *cur = stk.top().first;
            int &direction = stk.top().second;
            if (cur == nullptr) {
                stk.pop();
                continue;
            }
            if (direction == 2) {
                ans.push_back(cur->val);
            }
            direction++;

            if (direction == 1) {      // left child
                stk.push({cur->left, 0});
            } else if (direction == 2) {    // right child
                stk.push({cur->right, 0});
            } else {     // 孩子节点遍历完，退栈
                stk.pop();
            }
        }
        return ans;
    }
};
// @lc code=end

