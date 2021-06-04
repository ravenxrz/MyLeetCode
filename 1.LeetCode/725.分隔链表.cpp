#include "leetcode_base.h"
/*
 * @lc app=leetcode.cn id=725 lang=cpp
 *
 * [725] 分隔链表
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
  vector<ListNode *> splitListToParts(ListNode *root, int k) {
    vector<ListNode *> ans;
    ans.reserve(k);

    // Calculate length of the list started with "root"
    int len = 0;
    for (ListNode *p = root; p; p = p->next) {
      len++;
    }

    if (len <= k) {
      // Length of every list is less or equal than 1
      ListNode *p = root;
      while (p) {
        ListNode *save_p = p->next;
        p->next = nullptr;
        ans.push_back(p);
        p = save_p;
      }
      // The remaining "k-len" nodes are empty, so just set those all to nullptr
      ans.resize(k, nullptr);
    } else {
      int per_num = len / k;
      int leadding = len - k * per_num; // Represent the number of  "leading"
                                        // nodes  will be increased by 1

      ListNode *part_start_node = root;
      for (int part = 0; part < k; part++) {
        int cnt = 0;
        ListNode *prev = nullptr;
        ListNode *p = part_start_node;
        while (p && cnt < per_num) {
          prev = p;
          p = p->next;
          cnt++;
        }
        if (part < leadding) {
          prev = p;
          p = p->next;
        }
        prev->next = nullptr;
        // Get one part
        ans.push_back(part_start_node);
        part_start_node = p;
      }
    }
    return ans;
  }
};
// @lc code=end

int main() {
  ListNode *list = createList();
  Solution sol;
  sol.splitListToParts(list, 3);
  return 0;
}
