/*
 * @lc app=leetcode.cn id=86 lang=cpp
 *
 * [86] 分隔链表
 */
#include <iostream>

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
    ListNode *partition(ListNode *head, int x) {
        if(head == nullptr) return head;

        ListNode *pi = head, *pj , *ppj;

        // 找到第一个value 比 x小的node
        while(pi != nullptr && pi->val >= x){
            pi = pi->next;
        }
        ppj = pi;
        pj = pi->next;

        // 执行交换
        while(pj != nullptr){
            if(pj->val >= x){
                ppj = pj;
                pj = pj->next;
            }else{
                ppj->next = pj->next;
                pj->next = pi->next;
                pi->next = pj;

                pi = pj;
                pj = ppj->next;
            }
        }
        return head;
    }
};
// @lc code=end

