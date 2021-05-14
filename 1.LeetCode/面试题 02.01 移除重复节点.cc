//
// Created by raven on 5/14/21.
//

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
