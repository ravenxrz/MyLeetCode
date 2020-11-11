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
        if(head == nullptr)
            return nullptr;

        // 变量声明
        ListNode *pi,*ppi, *pj , *ppj;
        ListNode* new_head;
        pi = ppi = head;

        // 当第一个节点就比x大时，需要特殊处理
        bool head_large = false;
        if(head->val >= x){
            head_large = true;
            new_head = new ListNode(x - 1);
            new_head->next = head;
            pi = ppi = new_head;
        }


        // 找到第一个value 比 x小的node
        while(pi != nullptr && pi->val < x){
            ppi = pi;
            pi = pi->next;
        }
        if(pi == nullptr) return head;
        pi = ppi;
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
        return head_large ? new_head->next : head;
    }
};
// @lc code=end

