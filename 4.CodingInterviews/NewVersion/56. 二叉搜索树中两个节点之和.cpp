#include "leetcode_base.h"

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
private:
	unordered_set<int> values_;
public:
    bool findTarget(TreeNode* node, int k) {
		if(!node)	return false;
		if(values_.count(k - node->val)){
			return true;
		}
		values_.insert(node->val);
		return findTarget(node->left, k) || findTarget(node->right, k);
    }
};

int main()
{
	return 0;
}