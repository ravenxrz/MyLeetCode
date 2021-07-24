//
// Created by Raven on 2021/7/24.
//

class Solution {
public:
  vector<int> levelOrder(TreeNode *root) {
    if (root == nullptr)
      return {};
    
    vector<int> ans;
    queue<TreeNode *> qe;
    // init state
    qe.push(root);
    while (!qe.empty()) {
      auto cur_node = qe.front();
      qe.pop();
      ans.push_back(cur_node->val);
      if (cur_node->left)
        qe.push(cur_node->left);
      if (cur_node->right)
        qe.push(cur_node->right);
    }
    return ans;
  }
};
