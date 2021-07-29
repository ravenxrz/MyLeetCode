//
// Created by raven on 2021/7/28.
//
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(!head) return nullptr;
        // Old node -> New node
        unordered_map<Node *, Node *> umap;
        Node *new_head = new Node(head->val);
        Node *new_tail = new_head;
        umap[head] = new_head;
        
        // Copy straight line
        Node *old_p = head->next;
        while(old_p)
        {
            Node *node = new Node(old_p->val) ;
            umap[old_p] = node;
            // Insert node to the new list
            new_tail->next = node;
            new_tail = node;
            old_p = old_p->next;
        }
        // Copy random line
        old_p = head;
        Node *new_p = new_head;
        while(old_p){
            if(old_p->random){
                new_p->random = umap[old_p->random];
            }
            old_p = old_p->next;
            new_p = new_p->next;
        }
        
        return new_head;
    }
};

