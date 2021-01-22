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
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        // nullptr check
        if (l1 == nullptr && l2 == nullptr) return nullptr;
        else if (l1 == nullptr) return l2;
        else if (l2 == nullptr) return l1;
        
        // merge sort
        ListNode *new_head = new ListNode();
        ListNode *new_p = new_head;
        
        ListNode *p1 = l1;
        ListNode *p_next = nullptr;
        ListNode *p2 = l2;
        while (p1 != nullptr && p2 != nullptr) {
            if (p1->val <= p2->val) {
                // insert p1 to new list
                p_next = p1->next;
                p1->next = new_p->next;
                new_p->next = p1;
                // update pointer
                p1 = p1_next;
                new_p = p1;
            } else {
                // insert p2 to new list
                p_next = p2->next;
                p2->next = new_p->next;
                new_p->next = p2;
                // update pointer
                p2 = p_next;
                new_p = p2;
            }
        }
        // link remaining nodes
        if (p1 != nullptr) {
            new_p->next = p1;
        }
        
        if (p2 != nullptr) {
            new_p->next = p2;
        }
        
        ListNode *head = new_head->next;
        delete new_head;
        new_head = nullptr;
        return head;
    }
};
