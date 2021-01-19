/**
 * 给定单向链表的头指针和一个节点指针，定义一个函数在O(1)时间内删除节点。
 */

struct ListNode {
    int val;
    ListNode *next;
    
    ListNode(int x) : val(x), next(NULL) {}
};

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
    void DeleteNode(ListNode **pListNode, ListNode *pToBeDeleted)
    {
        if (pListNode == NULL || pToBeDeleted == NULL) {
            return;
        }
        // if the node needs to be delete is the head
        if(*pListNode == pToBeDeleted){
            (*pListNode) = (*pListNode)->next;
            return;
        }
        // else
        ListNode *pNext = pToBeDeleted->next;
        if(pNext == NULL){ // pToBeDeleted is the tail node
            // 线性scan，然后delete
            ListNode *p = *pListNode;
            while(p->next != NULL){
                p = p->next;
            }
            p->next = NULL;
        }else{
            // use pNext val to cover pToBeDeleted
            pToBeDeleted->val = pNext->val;
            pToBeDeleted->next = pNext->next;
        }
    }
};

int main()
{
    Solution sol;
    
    return 0;
}