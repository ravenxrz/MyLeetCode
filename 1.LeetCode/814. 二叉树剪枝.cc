//
// Created by raven on 5/24/21.
//
class Solution {
public:
  TreeNode *pruneTree(TreeNode *root) {
    bool ret = containOne(root);
    return ret ? root : nullptr;
  }

private:
  bool containOne(TreeNode *node) {
    if (node == nullptr)
      return false;
    bool left = containOne(node->left);
    bool right = containOne(node->right);
    if (!left)
      node->left = nullptr;
    if (!right)
      node->right = nullptr;
    return node->val == 1 || left || right;
  }
};