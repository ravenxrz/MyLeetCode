//
// Created by Raven on 2021/7/31.
//
void inOrderTraverse(TreeNode *root) {
  if (root == nullptr)
    return;
  inOrderTraverse(root->left);
  cout << root->val << ' ';
  inOrderTraverse(root->right);
}

void inOrderTraverse2(TreeNode *root) {
  TreeNode *p = root;
  stack<TreeNode *> stk;
  
  while (p || !stk.empty()) {
    if (p) {
      stk.push(p);
      p = p->left;
    } else {
      p = stk.top();
      stk.pop();
      cout << p->val << ' ';
      p = p->right;
    }
  }
}

int main()
{
  TreeNode *root = nullptr;
  createTree(&root);
  postOrderTraverse(root);
  cout << endl;
  postOrderTraverse2(root);
  return 0;
}
