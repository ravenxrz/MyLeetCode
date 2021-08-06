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
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        if (!headA || !headB)
            return nullptr;
        int lenA = 1;
        ListNode* pA = headA;
        int lenB = 1;
        ListNode* pB = headB;
        while (pA) {
            lenA++;
            pA = pA->next;
        }
        while (pB) {
            lenB++;
            pB = pB->next;
        }

		// Forward the longer list node
        pA = headA;
        pB = headB;
        if (lenA >= lenB) {
            for (int i = 0; i < lenA - lenB; i++) {
                pA = pA->next;
            }
        } else {
            for (int i = 0; i < lenB - lenA; i++) {
                pB = pB->next;
            }
        }

        while (pA != pB) {
            pA = pA->next;
            pB = pB->next;
        }
        return pA;
    }
};

int main() {
    return 0;
}