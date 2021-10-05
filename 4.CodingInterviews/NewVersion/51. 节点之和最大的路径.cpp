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
    int max_path{INT32_MIN};

   public:
    int maxPathSum(TreeNode* root) {
		pathSum(root);
		return max_path;
	}

   private:
    int pathSum(TreeNode* node) {
		if(node == nullptr) return 0;
		int left = max(0, pathSum(node->left));
		int right = max(0, pathSum(node->right));
		max_path = max(max_path, node->val + left + right);
		return max(node->val + left, node->val + right);
	}
};

int main() {
    return 0;
}