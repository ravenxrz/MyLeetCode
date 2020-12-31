/*
 * @lc app=leetcode.cn id=147 lang=cpp
 *
 * [147] 对链表进行插入排序
 */
#include <bits/stdc++.h>

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
    ListNode *insertionSortList(ListNode *head)
    {
        if (head == NULL || head->next == NULL) return head;
        // 前期准备
        ListNode *unsorted_head = head->next;
        head->next = NULL;
        ListNode *pre_head = new ListNode(-1);
        pre_head->next = head;
        
        // 执行插入排序
        while (unsorted_head != NULL) {
            ListNode *node = unsorted_head;
            unsorted_head = unsorted_head->next;
            
            // do insert
            ListNode *p = pre_head->next;
            ListNode *pp = pre_head;
            while (p != NULL) {
                if (p->val >= node->val) {
                    pp->next = node;
                    node->next = p;
                    break;
                }
                pp = p;
                p = p->next;
            }
            if (p == NULL) {
                pp->next = node;
                node->next = NULL;
            }
        }
        
        return pre_head->next;
    }
};
// @lc code=end

