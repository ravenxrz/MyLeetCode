#include "leetcode_base.h"
/*
 * @lc app=leetcode.cn id=1721 lang=cpp
 *
 * [1721] 交换链表中的节点
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
  ListNode *swapNodes(ListNode *head, int k) {
    ListNode dummy_head(0);
    dummy_head.next = head;

    // Get length of list started by head
    int len = 0;
    for (ListNode *p = head; p; p = p->next) {
      len++;
    }

    // Find two targeted positions used to swap
    ListNode *node1 = &dummy_head;
    ListNode *node2 = &dummy_head;
    for (int i = 0; i < k; i++) {
      node1 = node1->next;
      assert(node1);
    }
    for (int i = 0; i < len - k + 1; i++) {
      node2 = node2->next;
      assert(node2);
    }

    // Do swap op (value swap, not node swap)
    swap(node1->val, node2->val);
    return dummy_head.next;
  }
};
// @lc code=end
