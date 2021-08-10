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
        if (!l2)
            return l1;
        ListNode* p1 = l1;
        ListNode* p2 = l2;
        int carray = 0;
        int cur_val = 0;
        ListNode dumpy(0);
        ListNode* tail = &dumpy;
        // Merge two list
        while (p1 && p2) {
            cur_val = (p1->val + p2->val + carray) % 10;
            carray = (p1->val + p2->val + carray) / 10;
            ListNode* new_node = new ListNode(cur_val);
            tail->next = new_node;
            tail = new_node;
            p1 = p1->next;
            p2 = p2->next;
        }
        // If length of p1 is longer than p2's
        while (p1) {
            cur_val = (p1->val + carray) % 10;
            carray = (p1->val + carray) / 10;
            ListNode* new_node = new ListNode(cur_val);
            tail->next = new_node;
            tail = new_node;
            p1 = p1->next;
        }
        // If length of p2 is longer than p1's
        while (p2) {
            cur_val = (p2->val + carray) % 10;
            carray = (p2->val + carray) / 10;
            ListNode* new_node = new ListNode(cur_val);
            tail->next = new_node;
            tail = new_node;
            p2 = p2->next;
        }
		if(carray){
			tail->next = new ListNode(carray);
		}
        return dumpy.next;
    }
};

int main() {
    return 0;
}