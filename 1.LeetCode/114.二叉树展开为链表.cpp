/*
 * @lc app=leetcode.cn id=114 lang=cpp
 *
 * [114] 二叉树展开为链表
 */

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
    void flatten(TreeNode *root)
    {
        _flatten(root);
    }

private:
    TreeNode *_flatten(TreeNode *node)
    {
        if (node == nullptr) return nullptr;
        if(node->left ==nullptr && node->right == nullptr) return node;
        
        // save right node
        TreeNode *save_right = node->right;
        // flatten左边
        TreeNode *left_last = _flatten(node->left);
        // flatten 右边
        TreeNode *right_last = _flatten(save_right);
        if(left_last == nullptr) {
            return right_last;
        }else{
            node->right = node->left; node->left = nullptr;
            left_last->right = save_right;
            if(right_last == nullptr) return left_last;
            else return right_last;
        }
    }
};
// @lc code=end


int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(3);
    
    Solution sol;
    sol.flatten(root);
    return 0;
}