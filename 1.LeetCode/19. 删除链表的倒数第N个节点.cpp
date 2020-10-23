/**
 * 给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。

    示例：

    给定一个链表: 1->2->3->4->5, 和 n = 2.

    当删除了倒数第二个节点后，链表变为 1->2->3->5.
    说明：

    给定的 n 保证是有效的。

    进阶：

    你能尝试使用一趟扫描实现吗？
 */

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == nullptr)
            return nullptr;

        ListNode *p1 = head, *p2 = head;
        ListNode *pp1 = head;
        int counter = 0;
        
        while(counter != n-1){
            p2 = p2->next;
            counter++;
        }
        // 此时p1 -- p2之间 [p1,p2] 中元素共有n个
        while(p2->next!=nullptr){
            pp1 = p1;
            p1 = p1->next;
            p2 = p2->next;
        }
        
           // 执行删除
        if(p1 == head){ // 头节点特殊处理
            head = head->next;
        }else{          // 中间节点正常处理
            pp1->next = p1->next;
        }
        return head;
    }
};