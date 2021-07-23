#include "leetcode_base.h"

class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        if (l1 == nullptr) return l2;
        else if (l2 == nullptr) return l1;
        
        ListNode dumpyHead(0);
        ListNode *p1 = l1;
        ListNode *p2 = l2;
        ListNode *p = &dumpyHead;
        while (p1 && p2) {
            if (p1->val <= p2->val) {
                ListNode *next = p1->next;
                p1->next = p;
                p->next = p1;
                p = p1;
                p1 = next;
            } else {
                ListNode *next = p2->next;
                p2->next = p;
                p->next = p2;
                p = p2;
                p2 = next;
            }
        }
        if(p1) {
            p->next = p1;
        }else if(p2){
            p->next = p2;
        }
        return dumpyHead.next;
    }
};
