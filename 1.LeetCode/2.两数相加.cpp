/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    // 将l2的值加到了l1
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *p1 = l1, *p2 = l2;
        ListNode* pp = nullptr;
        int carry = 0;
        int value = 0;

        while(p1 != nullptr && p2 != nullptr){
            value = p1->val + p2->val + carry;
            carry = value / 10;
            p1->val = value % 10;
            pp = p1;
            p1 = p1->next;
            p2 = p2->next;
        }   

        while(p1 != nullptr){
            value = p1->val + carry;
            carry = value / 10;
            p1->val = value % 10;
            pp = p1;
            p1 = p1->next;
        }

        if(p2 != nullptr){
            pp->next = p2; // p2剩下的直接链接到l1上
            while(p2 != nullptr){
                value = p2->val + carry;
                carry = value / 10;
                p2->val = value % 10;
                pp = p2;
                p2 = p2->next;
            }
        }

        if(carry == 1){
            pp->next = new ListNode(1);
        }

        return l1;
    }
};
// @lc code=end