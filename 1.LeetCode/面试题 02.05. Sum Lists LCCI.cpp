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
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    if (!l1)
      return l2;
    if (!l2)
      return l1;

    ListNode dummy(0);
    ListNode *tail = &dummy;
    int carray = 0;
    while (l1 && l2) {
      int val = l1->val + l2->val + carray;
      carray = val / 10;
      tail->next = new ListNode(val % 10);
      tail = tail->next;
      l1 = l1->next;
      l2 = l2->next;
    }

    while (l1) {
      int val = l1->val + carray;
      carray = val / 10;
      tail->next = new ListNode(val % 10);
      tail = tail->next;
      l1 = l1->next;
    }

    while (l2) {
      int val = l2->val + carray;
      carray = val / 10;
      tail->next = new ListNode(val % 10);
      tail = tail->next;
      l2 = l2->next;
    }

    if (carray) {
      tail->next = new ListNode(carray);
    }

    return dummy.next;
  }
};