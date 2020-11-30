/*
 * @lc app=leetcode.cn id=142 lang=cpp
 *
 * [142] 环形链表 II
 */
#include <cstdio>
#include <iostream>
#include <stack>

using namespace std;

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
    ListNode *detectCycle(ListNode *head)
    {
        if (head == NULL) return NULL;
        ListNode *i = head;
        ListNode *j = head;
        
        do {
            i = i->next;
          
            j = j->next;
            if (j == NULL) break;
            j = j->next;
        } while (j != NULL && i != j);
        
        /* 非环 */
        if (j == NULL) return NULL;
        
        /* 判定环起点 */
        ListNode* pre = head;
        while(pre != i){
            pre = pre->next;
            i = i->next;
        }
        return i;
    }
};
// @lc code=end

int main()
{
    ListNode *list = new ListNode(3);
    ListNode *start = new ListNode(2);
    list->next = start;
    list->next->next = new ListNode(0);
    list->next->next->next = new ListNode(-4);
    list->next->next->next->next = start;
    Solution sol;
    cout << sol.detectCycle(list)->val;
    return 0;
}
