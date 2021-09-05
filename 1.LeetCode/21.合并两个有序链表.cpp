/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
 */
#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1)
            return l2;
        if (!l2)
            return l1;

        ListNode dumpyHead(0);
        ListNode* tail = &dumpyHead;
        while (l1 && l2) {
            if (l1->val <= l2->val) {
                ListNode* next_l1 = l1->next;
                l1->next = tail;
                tail->next = l1;
                l1 = next_l1;
            } else {
                ListNode* next_l2 = l2->next;
                l2->next = tail;
                tail->next = l2;
                l2 = next_l2;
            }
            tail = tail->next;
        }
        if (l1) {
            tail->next = l1;
        }
        if (l2) {
            tail->next = l2;
        }
        return dumpyHead.next;
    }
};