class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return head;
        
        ListNode dumpyHead(0);
        ListNode *cur = head;
        ListNode *next = cur->next;
        while(cur){
            // insert to dumpyHead
            cur->next = dumpyHead.next;
            dumpyHead.next = cur;
            cur = next;
            if(next) next = next->next;
        }
        return dumpyHead.next;
    }
};
