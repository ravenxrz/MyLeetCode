/*
 * @lc app=leetcode.cn id=83 lang=cpp
 *
 * [83] 删除排序链表中的重复元素
 */

#include <iostream>
#include <cstdio>
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
    ListNode *deleteDuplicates(ListNode *head) {
        if(head == NULL) return head;
        ListNode *i = head, *j = head;
        while(j != NULL){
            while(j != NULL && i->val == j->val){
                j = j->next;
            }
            if(j == NULL)break;

            i->next = j;
            i = j;
            j = j->next;
        }
        i->next = NULL;
        return head;
    }
};
// @lc code=end

