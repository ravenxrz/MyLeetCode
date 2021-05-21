//
// Created by raven on 5/21/21.
//
class Solution {
public:
  size_t ans = 0;
  int sumNumbers(TreeNode *root) {
    sum(root, 0);
    return ans;
  }

private:
  void sum(TreeNode *node, size_t base) {
    if (node == nullptr)
      return;
    base += node->val;
    // Left node
    if (!node->left && !node->right) {
      ans += base;
      return;
    }
    base *= 10;
    sum(node->left, base);
    sum(node->right, base);
  }
};
