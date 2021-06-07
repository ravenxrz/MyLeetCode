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
  ListNode *detectCycle(ListNode *head) {
    ListNode dummy(0);
    dummy.next = head;
    ListNode *slow = &dummy;
    ListNode *fast = &dummy;
    do {
      fast = fast->next;
      if (!fast)
        break;
      fast = fast->next;
      slow = slow->next;
    } while (fast && slow != fast);
    if (!fast)
      return nullptr; // What should be returned?
    slow = &dummy;
    while (slow != fast) {
      slow = slow->next;
      fast = fast->next;
    }
    return slow;
  }
};

int main() {
  ListNode *head = createList();
  head->next->next = head;
  Solution sol;
  cout << sol.detectCycle(head)->val << endl;
  return 0;
}