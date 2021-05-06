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

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
public:
  TreeNode *trimBST(TreeNode *root, int low, int high) {
    return cut(root, low, high);
  }

private:
  // Cut the sub-tree rooted with "root" and return the root of the new sub-tree
  TreeNode *cut(TreeNode *root, int low, int high) {
    if (root == nullptr) {
      return nullptr;
    }
    if (root->val < low) {
      // Find the right sub-tree, maybe there is a node which val is in the
      // bound [low,high]
      return cut(root->right, low, high);
    }
    if (root->val > high) {
      // Find the left sub-tree, maybe there is a node which val is in the bound
      // [low,high]
      return cut(root->left, low, high);
    }
    // this root val is in the bound [low, high]
    // continue to cut sub-trees recursively
    root->left = cut(root->left, low, high);
    root->right = cut(root->right, low, high);
    return root;
  }
};

int main() {
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(0);
  root->right = new TreeNode(2);
  Solution sol;
  TreeNode *new_root = sol.trimBST(root, 1, 2);
  return 0;
}
