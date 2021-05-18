//
// Created by raven on 5/18/21.
//
class Solution {
public:
  vector<vector<string>> printTree(TreeNode *root) { return print(root); }
  
  vector<vector<string>> print(TreeNode *node) {
    if (node == nullptr)
      return {};
    
    vector<vector<string>> left = print(node->left);
    vector<vector<string>> right = print(node->right);
    
    if (left.empty() && right.empty()) {
      return {{to_string(node->val)}};
    }
    
    if (left.size() < right.size()) {
      vector<vector<string>> tmp;
      tmp.resize(right.size(), vector<string>(right[0].size(), ""));
      if (!left.empty()) {
        int delta = tmp[0].size() / left[0].size();
        for (int i = 0; i < left.size(); i++) {
          for (int j = delta / 2; j < tmp[0].size(); j += delta) {
            tmp[i][j] = left[i][j / delta];
          }
        }
      }
      left = std::move(tmp);
    }
    
    if (left.size() > right.size()) {
      vector<vector<string>> tmp;
      tmp.resize(left.size(), vector<string>(left[0].size(), ""));
      if (!right.empty()) {
        int delta = (tmp[0].size() - 1) / right[0].size();
        for (int i = 0; i < right.size(); i++) {
          for (int j = delta / 2; j < tmp[0].size(); j += delta) {
            tmp[i][j] = right[i][j / delta];
          }
        }
      }
      right = std::move(tmp);
    }
    
    // assert
    assert(!left.empty() && left.size() == right.size());
    vector<string> cur_line;
    cur_line.resize(left[0].size() + right[0].size() + 1);
    cur_line[left[0].size()] = to_string(node->val);
    // 组装, 将right 拼接到 左边
    for (int i = 0; i < left.size(); i++) {
      left[i].push_back("");
      left[i].insert(left[i].end(), right[i].begin(), right[i].end());
    }
    // 将cur_line和left连接
    vector<vector<string>> ans(1 + left.size());
    ans[0] = std::move(cur_line);
    for (int i = 1; i < ans.size(); i++) {
      ans[i] = std::move(left[i - 1]);
    }
    return ans;
  }
};
