#include "leetcode_base.h"
/*
 * @lc app=leetcode.cn id=445 lang=cpp
 *
 * [445] 两数相加 II
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
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) { return getAns(l1, l2); }

private:
  ListNode *getAns(ListNode *l1, ListNode *l2) {
    ListNode dummy(0);
    int len1 = 0;
    int len2 = 0;
    for (ListNode *p = l1; p; p = p->next) {
      len1++;
    }
    for (ListNode *p = l2; p; p = p->next) {
      len2++;
    }
    int val = 0;
    if (len1 == len2) {
      val = process(&dummy, l1, l2);
    } else if (len1 > len2) {
      val = forward_process(&dummy, l1, l2, 0, len1 - len2);
    } else if (len1 < len2) {
      val = forward_process(&dummy, l2, l1, 0, len2 - len1);
    }

    if (val != 0) {
      ListNode *new_node = new ListNode(val);
      new_node->next = dummy.next;
      dummy.next = new_node;
    }
    return dummy.next;
  }

  int forward_process(ListNode *dummy, ListNode *need_forward, ListNode *keep,
                      int cur_step, int total_step) {
    if (cur_step == total_step) {
      return process(dummy, need_forward, keep);
    }
    int val =
        need_forward->val + forward_process(dummy, need_forward->next, keep,
                                            cur_step + 1, total_step);
    ListNode *new_node = new ListNode(val % 10);
    new_node->next = dummy->next;
    dummy->next = new_node;
    return val / 10;
  }

  // 首次传入到本函数时，node1和node2所代表的链表长度是相同的
  int process(ListNode *dummy, ListNode *node1, ListNode *node2) {
    if (!node1 && !node2) {
      return 0;
    } else {
      assert(node1 && node2);
    }
    // Generate a new node
    int val =
        node1->val + node2->val + process(dummy, node1->next, node2->next);
    ListNode *new_node = new ListNode(val % 10);
    new_node->next = dummy->next;
    dummy->next = new_node;
    return val / 10;
  }
};
// @lc code=end

int main() {
  ListNode *list1 = createList();
  ListNode *list2 = createList();
  Solution sol;
  sol.addTwoNumbers(list1, list2);
  return 0;
}