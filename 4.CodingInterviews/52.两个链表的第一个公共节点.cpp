#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    
    ListNode(int x) : val(x), next(NULL) {}
};

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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        if (headA == NULL || headB == NULL) return NULL;
        int lenA = 0;
        int lenB = 0;
        ListNode *pA = headA;
        ListNode *pB = headB;
        while (pA) {
            lenA++;
            pA = pA->next;
        }
        while (pB) {
            lenB++;
            pB = pB->next;
        }
        pA = headA;
        pB = headB;
        if (lenA > lenB) {
            for (int i = 0; i < lenA - lenB; i++) {
                pA = pA->next;
            }
        } else if (lenA < lenB) {
            for (int i = 0; i < lenB - lenA; i++) {
                pB = pB->next;
            }
        }
        while (pA && pB) {
            if (pA == pB) {
                return pA;
            }
            pA = pA->next;
            pB = pB->next;
        }
        return NULL;
    }
};
