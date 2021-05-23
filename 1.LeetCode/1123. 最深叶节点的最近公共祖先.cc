//
// Created by raven on 5/23/21.
//

class Solution {
public:
  typedef pair<TreeNode *, int> mypair;
  TreeNode *lcaDeepestLeaves(TreeNode *root) { return dfs(root, 0).first; }

private:
  mypair dfs(TreeNode *node, int level) {
    if (node == nullptr) {
      return {nullptr, level};
    }
    auto left = dfs(node->left, level + 1);
    auto right = dfs(node->right, level + 1);
    if (left.second == right.second) {
      return {node, left.second};
    }
    return left.second < right.second ? right : left;
  }
};

class Solution {
  unordered_set<TreeNode *> target_nodes;
  TreeNode *ans{nullptr};

public:
  TreeNode *lcaDeepestLeaves(TreeNode *root) {
    // Use level traverse to get the deepest nodes
    queue<TreeNode *> qe;
    qe.push(root);
    int cur_level = 1;
    int next_level = 0;

    unordered_set<TreeNode *> tmp_set;
    while (!qe.empty()) {
      auto cur = qe.front();
      qe.pop();
      tmp_set.insert(cur);
      cur_level--;
      if (cur->left) {
        qe.push(cur->left);
        next_level++;
      }
      if (cur->right) {
        qe.push(cur->right);
        next_level++;
      }
      if (cur_level == 0) {
        target_nodes.swap(tmp_set);
        tmp_set.clear();
        cur_level = next_level;
        next_level = 0;
      }
    }

    // Now all nodes inside "target_nodes" are located in deepest level
    // case1: if "target_nodes" only holds one node, we just need return it
    if (target_nodes.size() == 1)
      return *target_nodes.begin();
    // case2: if the number is ge 2, we need to traverse again
    ans = nullptr;
    traverse(root);
    return ans;
  }

private:
  vector<TreeNode *> traverse(TreeNode *node) {
    if (node == nullptr) {
      return {};
    }
    vector<TreeNode *> nodes1 = traverse(node->left);
    vector<TreeNode *> nodes2 = traverse(node->right);
    if (target_nodes.count(node)) {
      nodes1.push_back(node);
    }
    nodes1.insert(nodes1.end(), nodes2.begin(), nodes2.end());
    if (nodes1.size() == target_nodes.size() && !ans) {
      ans = node;
    }
    return nodes1;
  }
};

int main() {
  Solution sol;
  TreeNode *root = nullptr;
  createTree(&root);
  TreeNode *node = sol.lcaDeepestLeaves(root);
  cout << node->val << endl;
  return 0;
}
