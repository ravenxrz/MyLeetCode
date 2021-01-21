//
// Created by Raven on 2021/1/21.
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
    ListNode *getKthFromEnd(ListNode *head, int k)
    {
        if (head == NULL || k <= 0) return NULL;
        
        ListNode *p1 = head, *p2 = head;
        for (int i = 1; i <= k; i++) {
            if (p1 != NULL) p1 = p1->next;
            else return NULL;       // 节点数不足k个
        }
        while (p1!= NULL) {
            p1 = p1->next;
            p2 = p2->next;
        }
        return p2;
    }
};

int main(){
    return 0;
}