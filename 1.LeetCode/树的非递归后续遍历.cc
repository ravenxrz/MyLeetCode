//
// Created by Raven on 2021/7/31.
//
#include "leetcode_base.h"

void postOrderTraverse(TreeNode *root) {
  if (root == nullptr)
    return;
  postOrderTraverse(root->left);
  postOrderTraverse(root->right);
  cout << root->val << ' ';
}

void postOrderTraverse2(TreeNode *root) {
  TreeNode *p = root;
  stack<TreeNode *> stk;
  vector<TreeNode *> tmp;
  
  while (p || !stk.empty()) {
    if (p) {
      stk.push(p);
      tmp.push_back(p);
      p = p->right;
    } else {
      p = stk.top();
      stk.pop();
      p = p->left;
    }
  }
  
  // Reverse print
  for_each(tmp.rbegin(), tmp.rend(), [](TreeNode *x) { cout << x->val << ' '; });
}

int main() {
  TreeNode *root = nullptr;
  createTree(&root);
  postOrderTraverse(root);
  cout << endl;
  postOrderTraverse2(root);
  return 0;
}
