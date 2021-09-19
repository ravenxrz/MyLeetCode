#include "leetcode_base.h"

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		ListNode *pa = headA;
		ListNode *pb = headB;
		while(pa != pb){
			pa = pa == nullptr ? headB : pa->next;
			pb = pb == nullptr ? headA : pb->next;
		}
		return pa;
    }
};

int main()
{
	return 0;
}