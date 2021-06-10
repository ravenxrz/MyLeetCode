#include "leetcode_base.h"

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
private:
  unordered_set<int> values;

public:
  ListNode *removeDuplicateNodes(ListNode *head) {
    ListNode **node = &head;
    while (*node) {
      if (values.count((*node)->val)) {
        *node = (*node)->next;
      } else {
        values.insert((*node)->val);
        node = &(*node)->next;
      }
    }
    return head;
  }
};
