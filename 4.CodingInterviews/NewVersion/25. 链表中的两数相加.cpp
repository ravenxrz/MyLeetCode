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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if (!l1)
            return l2;
        else if (!l2)
            return l1;

        ListNode* nl1 = reverseList(l1);
        ListNode* nl2 = reverseList(l2);

        int carry = 0;
        ListNode* p1 = nl1;
        ListNode* p2 = nl2;
        ListNode dumpyHead(0);
        ListNode* tail = &dumpyHead;
        while (p1 && p2) {
            int val = p1->val + p2->val + carry;
            carry = val / 10;
            val = val % 10;
            ListNode* node = new ListNode(val);
            tail->next = node;
            tail = node;

            p1 = p1->next;
            p2 = p2->next;
        }

        while (p1) {
            int val = p1->val + carry;
            carry = val / 10;
            val = val % 10;
            ListNode* node = new ListNode(val);
            tail->next = node;
            tail = node;

            p1 = p1->next;
        }

        while (p2) {
            int val = p2->val + carry;
            carry = val / 10;
            val = val % 10;
            ListNode* node = new ListNode(val);
            tail->next = node;
            tail = node;

            p2 = p2->next;
        }

        if (carry) {
            tail->next = new ListNode(carry);
        }
		return reverseList(dumpyHead.next);
    }

   private:
    ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode* last_node = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return last_node;
    }
};