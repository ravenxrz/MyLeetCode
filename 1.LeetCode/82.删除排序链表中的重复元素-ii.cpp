/*
 * @lc app=leetcode.cn id=82 lang=cpp
 *
 * [82] 删除排序链表中的重复元素 II
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

    // 找到下一个无重复元素节点(包括本节点)
    ListNode *find_next_single_node(ListNode *node){
        if(node == NULL || node->next == NULL || node->val != node->next->val){
            return node;
        }

        while(node != NULL && node->next != NULL && node->val == node->next->val){
            node = node->next;
        }
        node = node->next;
        // check next node
        return find_next_single_node(node);
    }

    ListNode* deleteDuplicates(ListNode* head) {
        // 找到第一个无重复元素的节点
        head = find_next_single_node(head);
        if(head == NULL) return head;
        ListNode *i = head;
        ListNode *j = head->next;
        while(j != NULL){
            j = find_next_single_node(j);
            if(j == NULL) break;
            i->next = j;
            i = j;
            j = j->next;
        }
        i->next = NULL;
        return head;
    }
};
// @lc code=end

