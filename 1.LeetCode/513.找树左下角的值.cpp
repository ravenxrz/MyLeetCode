/*
 * @lc app=leetcode.cn id=513 lang=cpp
 *
 * [513] 找树左下角的值
 */
#include <cstdio>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


// @lc code=start
class Solution {
public:
    
    int ans = 0;
    int cur_height = 0;
    
    enum {
        left = 1,
        right = 2
    };
    
    void traverse(TreeNode *node, int height, int direction)
    {
        if (node == NULL) return;
        if (direction == right) {
            if (node->left == NULL && node->right == NULL && cur_height < height) {      // 一个单右叶子节点，可能在最后一层
                ans = node->val;
                cur_height = height;
                return;
            }
        } else if (direction == left) {
            if (cur_height < height) {
                ans = node->val;
                cur_height = height;
            }
            
        }
        traverse(node->left, height + 1, left);
        traverse(node->right, height + 1, right);
    }
    
    
    int findBottomLeftValue(TreeNode *root)
    {
        ans = root->val;
        cur_height = 0;
        traverse(root->left, 1, left);
        traverse(root->right, 1, right);
        return ans;
    }
};
// @lc code=end

