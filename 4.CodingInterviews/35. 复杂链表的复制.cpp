#include <iostream>
#include <unordered_map>
#include <map>

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
        // empty check
        if (head == NULL) return NULL;
        // 已加入的表
        unordered_map<Node *, Node *> added_map;
        
        Node *new_pre_head = new Node(-1);
        Node *old_p = head;
        Node *new_p = new_pre_head;
        while (old_p != NULL) {
            // 加入新节点
            new_p->next = new Node(old_p->val);
            // 将new_p->next和old_p的映射加入到added_map中，方便后续查看
            added_map[old_p] = new_p->next;
            
            new_p = new_p->next;
            old_p = old_p->next;
        }
        // 扫描一遍random pointer
        old_p = head;
        while (old_p != NULL) {
            if (old_p->random != NULL) {
                added_map[old_p]->random = added_map[old_p->random];
            }
            old_p = old_p->next;
        }
        
        Node *ret_head = new_pre_head->next;
        delete new_pre_head;
        new_pre_head = NULL;
        return ret_head;
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
