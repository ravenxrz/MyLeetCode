/*
 * @lc app=leetcode.cn id=61 lang=cpp
 *
 * [61] 旋转链表
 */

struct ListNode {
    int val;
    ListNode* next;
    ListNode()
        : val(0)
        , next(nullptr)
    {
    }
    ListNode(int x)
        : val(x)
        , next(nullptr)
    {
    }
    ListNode(int x, ListNode* next)
        : val(x)
        , next(next)
    {
    }
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
    /**
     * @brief 这里只采用了最简单的两次遍历，其实有个优化点，利用第一次遍历的
     *          信息可以尽量保留要移动的位置，但是实现要复杂些，现在这种情况也可以AC，
     *          就没有实现了
     * 
     * @param head 
     * @param k 
     * @return ListNode* 
     */
    ListNode* rotateRight(ListNode* head, int k)
    {
        if (head == nullptr)
            return head;
        // 计算链表长度
        int len = 0;
        ListNode* end = head;
        ListNode* p = head;
        while(p != nullptr)
        {
            len++;
            end = p;
            p = p->next;
        }
        
        end->next = head;
        // 计算需要移动的索引位置
        int pos = len - k % len;
        int counter = 1;
        p = head;
        while(counter != pos){
            p = p->next;
            counter++;
        }
        head = p->next;
        p->next = nullptr;
        return head;
    }
};
// @lc code=end
