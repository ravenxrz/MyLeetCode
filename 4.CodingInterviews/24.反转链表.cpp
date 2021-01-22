//
// Created by Raven on 2021/1/22.
//

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
    ListNode *reverseList(ListNode *head)
    {
        // empty check
        if (head == NULL) return NULL;
        
        ListNode *new_head = new ListNode();
        ListNode *old_p = head;
        while (old_p != null) {
            ListNode *old_next_p = old_p->next;
            // insert to new list
            old_p->next = new_head->next;
            new_head->next = old_p;
            old_p = old_next_p;
        }
        head = new_head->next;
        delete new_head;
        return head;
    }
};











