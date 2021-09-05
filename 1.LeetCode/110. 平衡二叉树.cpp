#include "leetcode_base.h"

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
   public:
    bool isBalanced(TreeNode* root) {
		bool balance = true;
		getHeight(root, balance);
		return balance;
	}

   private:
    int getHeight(TreeNode* root, bool& balance) {
        if (root == nullptr)
            return 0;
        if (!balance)
            return 0;
        int lh = getHeight(root->left, balance);
        int rh = getHeight(root->right, balance);
        if (abs(lh - rh) > 1) {
            balance = false;
        }
        return max(lh, rh) + 1;
    }
};