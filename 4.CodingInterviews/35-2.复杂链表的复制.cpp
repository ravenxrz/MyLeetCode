#include <iostream>

using namespace std;


class Node {
public:
    int val;
    Node *next;
    Node *random;
    
    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

/*
// Definition for a Node.
class node {
public:
    int val;
    node* next;
    node* random;
    
    node(int _val) {
        val = _val;
        next = null;
        random = null;
    }
};
*/
class Solution {
public:
    Node *copyRandomList(Node *head)
    {
        if(head == NULL)  return head;
        // step 1 生成新节点
        Node *cursor = head;
        while(cursor){
            Node *tmp = new Node(cursor->val);
            tmp->next = cursor->next;
            cursor->next = tmp;
            cursor = cursor->next->next;
        }
        // step 2 生成random ptr
        cursor = head;
        while(cursor){
            if(cursor->random){
                cursor->next->random = cursor->random->next;
            }
            cursor = cursor->next->next;
        }
        // step 3 拆分链表
        cursor = head;
        Node *new_head = cursor->next;
        while(cursor){
            Node *tmp = cursor->next->next;
            cursor->next = tmp->next;
            cursor->next = tmp;
            cursor = tmp;
        }
        return new_head;
    }
};

int main()
{
    Node *node1 = new Node(1);
    Node *node2 = new Node(2);
    Node *node3 = new Node(3);
    Node *node4 = new Node(4);
    
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    
    node1->random = node3;
    node2->random = node2;
    
    Solution sol;
    Node *new_p = sol.copyRandomList(node1);
    while (new_p) {
        cout << new_p << " " << new_p->random << endl;
        new_p = new_p->next;
    }
    return 0;
}
