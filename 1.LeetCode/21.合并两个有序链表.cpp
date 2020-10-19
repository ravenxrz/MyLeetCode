/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
 */
#include <iostream>
#include <vector>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == nullptr)
            return l2;
        if(l2 == nullptr)
            return l1;

        ListNode *head = new ListNode(-1);
        ListNode *hp = head;
        ListNode *p1 = l1;
        ListNode *p2 = l2;

        while(p1 != nullptr && p2 != nullptr){
            if(p1->val <= p2->val){
                ListNode *pn1 = p1->next;
                insert(hp, p1);
                hp = p1;
                p1 = pn1;
            }else{
                ListNode *pn2 = p2->next;
                insert(hp, p2);
                hp = p2;
                p2 = pn2;
            }
        }

        if(p1 == nullptr){
            hp->next = p2;
        }else if(p2 == nullptr){
            hp->next = p1;
        }

        hp = head->next;
        delete head;
        return hp;
    }

    void insert(ListNode *node1, ListNode *node2){
        node2->next = node1->next;
        node1->next = node2;
    }
};
// @lc code=end

