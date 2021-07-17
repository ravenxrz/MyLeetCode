#include "leetcode_base.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
  vector<int> ans;

public:
  vector<int> reversePrint(ListNode *head) {
    ans.clear();
    recursive_print(head);
    return ans;
  }

private:
  void recursive_print(ListNode *node) {
    if (node == nullptr)
      return;
    recursive_print(node->next);
    ans.push_back(node->val);
  }
};

int main() {
  return 0;
}
