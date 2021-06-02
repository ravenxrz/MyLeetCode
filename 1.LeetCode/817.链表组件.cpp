#include "leetcode_base.h"

/*
 * @lc app=leetcode.cn id=817 lang=cpp
 *
 * [817] 链表组件
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
  int numComponents(ListNode *head, vector<int> &nums) {
    if (head == nullptr)
      return 0;
    std::unordered_set<int> table;
    // Insert nums into table
    for (auto val : nums) {
      table.insert(val);
    }

    int ccnt = 0; // component ccnt
    bool start = false;
    for (ListNode *p = head; p; p = p->next) {
      if (table.count(p->val)) {
        if (!start) {
          ccnt++;
          start = true;
        }
      } else {
        start = false;
      }
    }

    return ccnt;
  }
};
// @lc code=end
