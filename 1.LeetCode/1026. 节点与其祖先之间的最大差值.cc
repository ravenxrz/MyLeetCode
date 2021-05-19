//
// Created by raven on 5/19/21.
//


class Solution {
  int max_value = 0;

public:
  int maxAncestorDiff(TreeNode *root) {
    assert(root);
    traverse(root->left, root->val, root->val);
    traverse(root->right, root->val, root->val);
    return max_value;
  }
  
  void traverse(TreeNode *node, int min_v, int max_v) {
    if (node == nullptr)
      return;
    max_value = max(
        {max_value, std::abs(node->val - min_v), std::abs(node->val - max_v)});
    if (min_v > node->val)
      min_v = node->val;
    if (max_v < node->val)
      max_v = node->val;
    traverse(node->left, min_v, max_v);
    traverse(node->right, min_v, max_v);
  }
};


class Solution {
  int max_value = 0;

public:
  int maxAncestorDiff(TreeNode *root) {
    traverse(root);
    return max_value;
  }
  
  unordered_set<int> traverse(TreeNode *node) {
    if (node == nullptr)
      return {};
    unordered_set<int> left = traverse(node->left);
    unordered_set<int> right = traverse(node->right);
    // Calculate max abs value among left and right
    for (auto val : left) {
      max_value = max(max_value, std::abs(val - node->val));
    }
    for (auto val : right) {
      max_value = max(max_value, std::abs(val - node->val));
    }
    // Combine two sets
    left.insert(node->val);
    left.insert(right.begin(),right.end());
    return std::move(left);
  }
};



