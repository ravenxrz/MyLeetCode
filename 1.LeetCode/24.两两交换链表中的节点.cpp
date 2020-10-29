/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
 */
#include <iostream>
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
class Solution
{
public:
    ListNode *swapPairs(ListNode *head)
    {
        if(head == nullptr || head->next == nullptr)
            return head;

        // 3个指针
        ListNode *pp1, *p1, *p2;
        // 人为新节点
        ListNode *new_head = new ListNode(0);
        new_head->next = head;
        pp1 = new_head;
        p1 = head;
        p2 = head->next;

        ListNode *tmp;
        // 执行交换
        while(p2 != nullptr){
            // 交换
            p1->next = p2->next;
            p2->next = p1;
            pp1->next = p2;
            // 恢复p1和p2的次数
            tmp = p1;
            p1 = p2;
            p2 = tmp;
            // 现在次序为 pp1, p1,p2
            // 尝试增加p2 2次
            p2 = p2->next;
            if(p2 == nullptr){
                break;
            }
            p2 = p2->next;
            p1 = p1->next->next;
            pp1 = pp1->next->next;
        }
        return new_head->next;
    }
};
// @lc code=end

int main()
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    Solution solution;
    solution.swapPairs(head);
    return 0;
}