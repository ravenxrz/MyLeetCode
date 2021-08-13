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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dumpy_head(0);
        dumpy_head.next = head;
        ListNode* p1 = &dumpy_head;
        // Forward n steps
        for (int i = 0; i < n && p1; i++) {
            p1 = p1->next;
        }
		if(!p1) return head;		// n is larger than length of list 
		ListNode* target = &dumpy_head;
		ListNode* pre_target = &dumpy_head;
		while(p1){
			pre_target = target;
			target = target->next;
			p1 = p1->next;
		}
		assert(target);
		pre_target->next = target->next;
		return dumpy_head.next;
    }
};

int main() {
	Solution sol;
	ListNode *head;
	head = createList();
	cout << sol.removeNthFromEnd(head, 4)->val << endl;

    return 0;
}