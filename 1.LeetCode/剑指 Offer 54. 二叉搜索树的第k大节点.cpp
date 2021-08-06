#include "leetcode_base.h"

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
   private:
    int ans;
    int cnt;

   public:
    int kthLargest(TreeNode* root, int k) { 
		ans = 0;
		cnt = 0;
		inOrderGet(root, k);
		return ans;
	 }

   private:
   void inOrderGet(TreeNode *node, int k){
	   if(node == nullptr){
		   return;
	   }
	   inOrderGet(node->right, k);
	   cnt++;
	   if(cnt == k){
		   ans = node->val;
		   return;
	   } 
	   inOrderGet(node->left, k);
   }

};

int main() {
    return 0;
}