//
// Created by Raven on 2021/7/31.
//
void preOrderTraverse(TreeNode *node) {
  if (node == nullptr)
    return;
  cout << node->val << ' ';
  preOrderTraverse(node->left);
  preOrderTraverse(node->right);
}

void preOrderTraverse2(TreeNode *node) {
  if (node == nullptr)
    return;
  TreeNode *p = node;
  stack<TreeNode *> stk;
  
  while (p || !stk.empty()) {
    if (p) {
      cout << p->val << ' ';
      stk.push(p);
      p = p->left;
    } else {
      p = stk.top();
      stk.pop();
      p = p->right;
    }
  }
  cout << endl;
}

int main() {
  TreeNode *root = nullptr;
  createTree(&root);
  preOrderTraverse(root);
  cout << endl;
  preOrderTraverse2(root);
  return 0;
}
