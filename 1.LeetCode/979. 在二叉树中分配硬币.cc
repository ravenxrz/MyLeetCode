//
// Created by raven on 5/25/21.
//
class Solution {
  int ans = 0;

public:
  int distributeCoins(TreeNode *root) {
    dfs(root);
    return ans;
  }

private:
  int dfs(TreeNode *node) {
    if (node == nullptr) {
      return 0;
    }
    int left = dfs(node->left);
    int right = dfs(node->right);
    ans += std::abs(left) + std::abs(right);
    return node->val + left + right - 1;
  }
};
