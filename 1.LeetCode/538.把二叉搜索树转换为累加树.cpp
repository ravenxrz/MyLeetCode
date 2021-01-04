/*
 * @lc app=leetcode.cn id=538 lang=cpp
 *
 * [538] 把二叉搜索树转换为累加树
 */

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
    TreeNode* convertBST(TreeNode* root) {
        in_order_traverse(root);
        // 求和
        int sum = 0;
        for (auto &node : nodes) {
            sum += node->val;
        }
        // 重新赋值
        for (auto & node : nodes) {
            int val = node->val;
            node->val = sum;
            sum -= val;
        }
        return root;
    }
private:
    // 中序遍历一次
    void in_order_traverse(TreeNode *node)
    {
        if (node == nullptr) {
            return;
        }
        in_order_traverse(node->left);
        nodes.push_back(node);
        in_order_traverse(node->right);
    }

private:
    vector<TreeNode *> nodes;
};
// @lc code=end

