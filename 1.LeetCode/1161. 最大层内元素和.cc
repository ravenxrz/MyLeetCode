//
// Created by raven on 5/12/21.
//
class Solution {
public:
  int maxLevelSum(TreeNode *root) {
    assert(root != nullptr);
    queue<TreeNode *> qt;
    qt.push(root);
    int cur_nodes = 1;
    int next_nodes = 0;
    int max_value = INT_MIN;
    int min_level = 1;
    int tmp_sum = 0;
    int cur_level = 1;
    
    while (!qt.empty()) {
      auto *cur = qt.front();
      qt.pop();
      tmp_sum += cur->val;
      cur_nodes--;
      
      if (cur->left) {
        qt.push(cur->left);
        next_nodes++;
      }
      if (cur->right) {
        qt.push(cur->right);
        next_nodes++;
      }
      
      if (cur_nodes == 0) {
        cur_nodes = next_nodes;
        next_nodes = 0;
        if(max_value < tmp_sum){
          max_value = tmp_sum;
          min_level = cur_level;
        }
        tmp_sum = 0;
        cur_level++;
      }
    }
    return min_level;
  }
};
