#include "leetcode_base.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
  void reorderList(ListNode *head) {
    if (head == nullptr)
      return;

    // Find the middle node
    ListNode dummy_head(0);
    dummy_head.next = head;
    ListNode *slow = &dummy_head;
    ListNode *fast = &dummy_head;
    while (fast) {
      fast = fast->next;
      if (!fast)
        break;
      fast = fast->next;
      slow = slow->next;
    }
    ListNode *half_list = slow->next;
    slow->next = nullptr; // Cut left half list

    // Reverse right half list
    dummy_head.next = nullptr;
    for (ListNode *p = half_list; p;) {
      ListNode *next_p = p->next;
      p->next = dummy_head.next;
      dummy_head.next = p;
      p = next_p;
    }

    // Reorder list
    ListNode *p1 = head;
    ListNode *p2 = dummy_head.next;
    while (p2) {
      ListNode *next_p2 = p2->next;
      ListNode *next_p1 = p1->next;

      p2->next = p1->next;
      p1->next = p2;

      p1 = next_p1;
      p2 = next_p2;
    }
    return;
  }
};
// @lc code=end

int main() {
  Solution sol;
  ListNode *head = createList();
  sol.reorderList(head);
  return 0;
}