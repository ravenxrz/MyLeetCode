#include "leetcode_base.h"
/*
 * @lc app=leetcode.cn id=1171 lang=cpp
 *
 * [1171] 从链表中删去总和值为零的连续节点
 */

// @lc code=start
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
  ListNode *removeZeroSumSublists(ListNode *head) {
    // Convert to arr, and find a sub-array which contains a consecutive seq
    // whose sum value is zero
    vector<int> arr;
    for (ListNode *p = head; p; p = p->next) {
      arr.push_back(p->val);
    }

    // TODO: maybe I should use a two-dimesion array dp[i][j]
    // representing the sum value of arr[i] to arr[j] to get the answer
    int max_span = 0;
    int start = -1;
    int end = -1;
    for (int i = 0; i < arr.size(); i++) {
      int sum = 0;
      for (int j = i; j < arr.size(); j++) {
        sum += arr[j];
        if (sum == 0 && (j - i + 1) > max_span) {
          max_span = (j - i + 1);
          start = i;
          end = j;
        }
      }
    }

    // No consecutive seq whose sum value is zero
    if (start == -1)
      return head;

    ListNode dummy(0);
    dummy.next = head;
    ListNode *startp = &dummy;
    for (int i = 0; i < start; i++) {
      startp = startp->next;
    }
    ListNode *endp = &dummy;
    for (int i = 0; i < end + 2; i++) {
      endp = endp->next;
    }
    // I choose to not free node pointers intentionally
    startp->next = endp;
    return removeZeroSumSublists(dummy.next);
  }
};
// @lc code=end
