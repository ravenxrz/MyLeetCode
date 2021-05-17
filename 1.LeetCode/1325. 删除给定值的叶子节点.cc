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
  TreeNode *removeLeafNodes(TreeNode *root, int target) {
    postOrderTraverse(&root, target);
    return root;
  }

private:
  void postOrderTraverse(TreeNode **node, int target) {
    if (*node == nullptr)
      return;
    postOrderTraverse(&(*node)->left, target);
    postOrderTraverse(&(*node)->right, target);
    if (!(*node)->left && !(*node)->right && (*node)->val == target) {
      //      delete *node;
      *node = nullptr;
    }
  }
};

int main() {
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(1);
  root->right = new TreeNode(1);
  Solution sol;
  root = sol.removeLeafNodes(root, 1);
  (void)(root);
  return 0;
}
