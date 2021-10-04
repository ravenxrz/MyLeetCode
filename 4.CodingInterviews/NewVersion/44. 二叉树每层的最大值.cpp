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
public:
    vector<int> largestValues(TreeNode* root) {
		if(!root) return {};

		vector<int> ans;
		int cur_level_nums = 0;
		int next_level_nums = 0;
		int max_value = INT32_MIN;
		queue<TreeNode*> qe;
		/* init state */	
		qe.push(root);
		cur_level_nums = 1;
		/* bfs */	
		while(!qe.empty()){
			/* get front node */
			TreeNode* cur = qe.front();
			qe.pop();
			cur_level_nums--;
			max_value = max(max_value, cur->val);

			/* push next level nodes */
			if(cur->left){
				qe.push(cur->left);
				next_level_nums++;
			}
			if(cur->right){
				qe.push(cur->right);
				next_level_nums++;
			}

			/* check if cur_level_nums = 0, if so, switch to next level */
			if(cur_level_nums == 0){
				cur_level_nums = next_level_nums;
				next_level_nums = 0;
				ans.push_back(max_value);
				max_value = INT32_MIN;
			}
		}
		return ans;
    }
};

int main()
{
	return 0;
}