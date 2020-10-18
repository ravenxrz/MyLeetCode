/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <cstdio>
class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        if (head == NULL)
            return head;

        ListNode *new_head = new ListNode(-1);
        ListNode *p = head;
        while (p->next != NULL)
        {
            ListNode *temp = p->next;
            insert(new_head, p);
            p = temp;
        }
        // copy the final node to the new_head value
        new_head->val = p->val;
        // delete head ?
        return new_head;
    }

    void insert(ListNode *head, ListNode *node)
    {
        node->next = head->next;
        head->next = node;
    }
};
// @lc code=end


int main()
{

    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    Solution sol;
    sol.reverseList(head);

    return 0;
}