//
// Created by raven on 5/29/21.
//

class Solution {
  bool
      ans; // Requires: ans need to be set to true before calling check function
public:
  bool flipEquiv(TreeNode *root1, TreeNode *root2) {
    ans = true;
    Compare(root1, root2);
    return ans;
  }

private:
  bool NotFlipSame(TreeNode *node1, TreeNode *node2) {
    bool ret1 = !node1->left && !node2->left;   // 左空
    bool ret2 = !node1->right && !node2->right; // 右空
    bool ret3 = node1->left && node2->left &&
                node1->left->val == node2->left->val; // 左非空
    bool ret4 = node1->right && node2->right &&
                node1->right->val == node2->right->val; // 右非空

    return (ret1 && ret2)    // 左右均空
           | (ret1 && ret4)  // 左空右非空且相等
           | (ret3 && ret2)  // 左非空右空
           | (ret3 && ret4); // 左右均非空且相等
  }

  bool FlipSame(TreeNode *node1, TreeNode *node2) {
    bool ret1 = !node1->left && !node2->right;
    bool ret2 = !node1->right && !node2->left;
    bool ret3 =
        node1->left && node2->right && node1->left->val == node2->right->val;
    bool ret4 =
        node1->right && node2->left && node1->right->val == node2->left->val;

    return (ret1 && ret2) | (ret1 && ret4) | (ret3 && ret2) | (ret3 && ret4);
  }

  void Compare(TreeNode *node1, TreeNode *node2) {
    // There is no need to check anymore now that we have got the answer already
    if (!ans)
      return;
    if (!node1 && !node2)
      return;
    else if ((!node1 && node2) || (node1 && !node2)) {
      ans = false;
      return;
    }
    // node1 && node2
    if (node1->val != node2->val) {
      ans = false;
      return;
    }
    // Check whether four subtrees of two nodes are same or not with no flipping
    if (NotFlipSame(node1, node2)) {
      Compare(node1->left, node2->left);
      Compare(node1->right, node2->right);
    } else if (FlipSame(node1, node2)) {
      Compare(node1->left, node2->right);
      Compare(node1->right, node2->left);
    } else {
      ans = false;
    }
  }
};

int main() {
  TreeNode *root1 = nullptr;
  TreeNode *root2 = nullptr;
  createTree(&root1);
  createTree(&root2);
  Solution sol;
  cout << sol.flipEquiv(root1, root2) << endl;
  return 0;
}
