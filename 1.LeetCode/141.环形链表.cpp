/*
 * @lc app=leetcode.cn id=141 lang=cpp
 *
 * [141] 环形链表
 */


 struct ListNode {
     int val;
      ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
  };

// @lc code=start
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
    bool hasCycle(ListNode *head) {
        if(head == nullptr || head->next == nullptr)
            return false;

        ListNode* slow = head;
        ListNode* fast = head->next->next;
        if(fast == nullptr)
            return false;
        
        while(fast != slow){
            slow = slow->next;
            fast = fast->next;
            if(fast == nullptr)
                return false;
            fast = fast->next;
            if(fast == nullptr)
                return false;
        }
        return true;
    }
};
// @lc code=end

