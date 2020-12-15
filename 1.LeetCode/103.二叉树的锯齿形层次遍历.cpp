/*
 * @lc app=leetcode.cn id=103 lang=cpp
 *
 * [103] 二叉树的锯齿形层次遍历
 */
#include <vector>
#include <queue>
#include <stack>

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
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        if (root == nullptr) return {};
        
        // insert root
        vector<vector<int>> ans;
        // two extra stack
        stack<TreeNode *> stk1;
        stack<TreeNode *> stk2;
        stk1.push(root);
        int level = 0;
        TreeNode *cur = nullptr;
        
        while (!stk1.empty() || !stk2.empty()) {
            if (level % 2 == 1) {  // 当前在奇数层
                while (!stk2.empty()) {
                    cur = stk2.top();
                    stk2.pop();
                    if (cur == nullptr) continue;
                    // 从右往左加
                    stk1.push(cur->right);
                    stk1.push(cur->left);
                    // 加入到ans
                    if (ans.size() <= level) {
                        ans.push_back({cur->val});
                    } else {
                        ans[level].push_back(cur->val);
                    }
                }
            } else { // 当前在偶数层
                while (!stk1.empty()) {
                    cur = stk1.top();
                    stk1.pop();
                    if (cur == nullptr) continue;
                    // 从左往右加
                    stk2.push(cur->left);
                    stk2.push(cur->right);
                    // 加入到ans
                    if (ans.size() <= level) {
                        ans.push_back({cur->val});
                    } else {
                        ans[level].push_back(cur->val);
                    }
                }
            }
            level++;
        }
        return ans;
    }
};
// @lc code=end

