//
// Created by raven on 5/20/21.
//

class Solution {
public:
  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
    return LCA(root, p, q);
  }

private:
  TreeNode *LCA(TreeNode *node, TreeNode *p, TreeNode *q) {
    if (node == p || node == q || node == nullptr)
      return node;
    TreeNode *left = LCA(node->left, p, q);
    TreeNode *right = LCA(node->right, p, q);
    if (left && right)
      return node;
    else if (left)
      return left;
    else
      return right; // returns right or nullptr
  }
};
