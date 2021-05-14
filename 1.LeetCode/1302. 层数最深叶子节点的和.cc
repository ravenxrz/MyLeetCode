#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

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
class Solution {
public:
  int deepestLeavesSum(TreeNode *root) {
    assert(root != nullptr);
    queue<TreeNode *> qe;
    int cur_level_num = 0;
    int next_level_num = 0;
    int ans_sum = 0;

    qe.push(root);
    cur_level_num = 1;
    while (!qe.empty()) {
      auto *node = qe.front();
      qe.pop();
      ans_sum += node->val;
      cur_level_num--;
      if (node->left) {
        qe.push(node->left);
        next_level_num++;
      }
      if (node->right) {
        qe.push(node->right);
        next_level_num++;
      }
      if (cur_level_num == 0) {
        if (next_level_num == 0)
          return ans_sum;
        cur_level_num = next_level_num;
        next_level_num = 0;
        ans_sum = 0;
      }
    }
    return -1;
  }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */

int main() {
  string str1 = "";
  string str2 = "h";
  cout << str1.compare(str2) << endl;
  return 0;
}
