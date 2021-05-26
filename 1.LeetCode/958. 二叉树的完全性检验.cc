//
// Created by raven on 5/26/21.
//

class Solution {
public:
  bool isCompleteTree(TreeNode *root) {
    queue<TreeNode *> qe;
    qe.push(root);
    bool end = false;
    while (!qe.empty()) {
      auto *cur = qe.front();
      qe.pop();
      if (cur == nullptr) {
        if (!end)
          end = true;
      } else {
        if (end)
          return false;
        qe.push(cur->left);
        qe.push(cur->right);
      }
    }
    return true;
  }
};



class Solution {
public:
  bool isCompleteTree(TreeNode *root) {
    queue<TreeNode *> qe;
    qe.push(root);
    int height_node_num = 1;
    bool may_last_level = false;
    int cur_level = 1;
    int next_level = 0;

    while (!qe.empty()) {
      if (may_last_level) {
        // Handle the last level case
        while (!qe.empty() && qe.front()) {
          if (qe.front()->left || qe.front()->right)
            return false;
          qe.pop();
        }
        qe.pop(); // the front of qe is nullptr now, we need to pop it first
        // then check if there are any non-nullptr node inside the qe
        while (!qe.empty() && !qe.front())
          qe.pop();
        return qe.empty(); // If qe.empty() == true, indicating all remaining
        // nodes are nullptr since the first nullptr node in
        // the last level of this tree; else qe.empty() == false,
        // indicating there are some nodes which are non-nullptr
      }

      auto *cur = qe.front();
      qe.pop();
      // assert(cur)
      qe.push(cur->left);
      qe.push(cur->right);
      if (cur->left)
        next_level++;
      if (cur->right)
        next_level++;
      cur_level--;
      if (cur_level == 0) {
        cur_level = next_level;
        height_node_num <<= 1;
        if (height_node_num != next_level) {
          // the node number of  one level is not equal to the target
          // height_node_num which means we have reached the last level
          may_last_level = true;
        }
        next_level = 0;
      }
    }
    return true;
  }
};
