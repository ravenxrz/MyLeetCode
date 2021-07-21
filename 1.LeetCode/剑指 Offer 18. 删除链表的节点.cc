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
public:
  ListNode *deleteNode(ListNode *head, int val) {
    assert(head != nullptr);
    ListNode dumpyHead(0);
    dumpyHead.next = head;
    ListNode *pre = &dumpyHead;
    ListNode *next = pre->next;
    while (next && next->val != val) {
      pre = next;
      next = next->next;
    }
    if (next) {
      pre->next = next->next;
    }
    return dumpyHead.next;
  }
};

int main() {
  Solution sol;
  return 0;
}
