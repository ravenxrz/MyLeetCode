#include "leetcode_base.h"
/*
 * @lc app=leetcode.cn id=1019 lang=cpp
 *
 * [1019] 链表中的下一个更大节点
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
  vector<int> nextLargerNodes(ListNode *head) {
    vector<int> ans(10010, 0);
    // ans.resize(10010);
    // pair.first: indice of node in ans
    // pair.second: node value
    stack<pair<int, int>> stk;
    int len = 0;
    for (ListNode *p = head; p; p = p->next) {
      while (!stk.empty() && p->val > stk.top().second) {
        auto cur = stk.top();
        stk.pop();
        ans[cur.first] = p->val;
      }
      stk.push({len, p->val});
      len++;
    }
    // while (!stk.empty()) {
    //   auto cur = stk.top();
    //   stk.pop();
    //   ans[cur.first] = 0;
    // }

    ans.resize(len);
    return ans;
  }
};
// @lc code=end
