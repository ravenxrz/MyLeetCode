#include "leetcode_base.h"
/*
 * @lc app=leetcode.cn id=92 lang=cpp
 *
 * [92] 反转链表 II
 */

// @lc code=start
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
  ListNode *reverseBetween(ListNode *head, int left, int right) {
    ListNode dummy1(0);
    dummy1.next = head;
    // Find the previous node of "left" node
    ListNode *left_node_prev = &dummy1;
    for (int i = 0; i < left - 1; i++) {
      left_node_prev = left_node_prev->next;
    }
    // Find the "right" node
    ListNode *right_node = left_node_prev;
    for (int i = 0; i < right - left + 2; i++) {
      right_node = right_node->next;
    }
    // Execute reversing
    ListNode tmp_dummy(0);
    ListNode *tail_node = nullptr;
    for (ListNode *p = left_node_prev->next; p != right_node;) {
      if (tmp_dummy.next == nullptr) {
        tail_node = p;
      }
      ListNode *next_ptr = p->next;
      p->next = tmp_dummy.next;
      tmp_dummy.next = p;
      p = next_ptr;
    }
    // Concate three parts of list together
    left_node_prev->next = tmp_dummy.next;
    tail_node->next = right_node;
    return dummy1.next;
  }
};
// @lc code=end
