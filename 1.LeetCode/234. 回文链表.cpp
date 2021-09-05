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
    bool isPalindrome(ListNode* head) {
        if (!head)
            return true;

        ListNode* fast = head;
        ListNode* slow = head;

        // find the mid point
        while (fast->next && fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
        }

        // reverse the right side half list
        ListNode* prev = nullptr;
        while (slow) {
            ListNode* tmp_next = slow->next;
            slow->next = prev;
            prev = slow;
            slow = tmp_next;
        }

        // Do palindrome check
        while (head && prev) {
            if (head->val != prev->val)
                return false;
            head = head->next;
            prev = prev->next;
        }
        return true;
    }
};
