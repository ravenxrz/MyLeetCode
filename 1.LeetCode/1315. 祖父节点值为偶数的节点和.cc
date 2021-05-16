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
  int sum = 0;

public:
  int sumEvenGrandparent(TreeNode *root) {
    treeAdd(root, -1, -1);
    return sum;
  }

private:
  void treeAdd(TreeNode *node, int parent, int grandparent) {
    if (node == nullptr) {
      return;
    }
    if ((grandparent & 1) == 0) {
      sum += node->val;
    }
    treeAdd(node->left, node->val, parent);
    treeAdd(node->right, node->val, parent);
  }
};

int main(){
  return 0;
}
