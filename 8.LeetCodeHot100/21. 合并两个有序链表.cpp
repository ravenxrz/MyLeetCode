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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		if(!l1) return l2;
		if(!l2) return l1;
		// Both lists are not empty
		ListNode dumpyHead(0);
		ListNode *tail = &dumpyHead;
		ListNode *p1 = l1;
		ListNode *p2 = l2;
		ListNode *save = nullptr;
		while(p1 && p2){
			if(p1->val <= p2->val){
				save = p1->next;
				p1->next = tail->next;
				tail->next = p1;
				tail = p1;	
				p1 = save;
			}else{
				save = p2->next;
				p2->next = tail->next;
				tail->next = p2;
				tail = p2;
				p2 = save;
			}
		}
		if(p1){
			tail->next = p1;
		}
		if(p2){
			tail->next = p2;
		}
		return dumpyHead.next;
    }
};

int main()
{
	Solution sol;
	return 0;
}
