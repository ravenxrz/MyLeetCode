class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr)  return nullptr;
        else if(head->next == nullptr) return head;
        
        ListNode *pre = nullptr;
        ListNode *cur = head;
        ListNode *next = cur->next;
        
        while(cur){
            cur->next = pre;
            pre = cur;
            cur = next;
            if(next) next = next->next;
        }
        return pre;
    }
};
