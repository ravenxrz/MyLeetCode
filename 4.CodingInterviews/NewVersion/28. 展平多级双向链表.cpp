#include "leetcode_base.h"

class Node {
   public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};

class Solution {
   public:
    Node* flatten(Node* head) {
		_flatten(head);
		return head;
	}

   private:
    Node* _flatten(Node* node) {
        Node* prev = nullptr;
        while (node && node->child == nullptr) {
            prev = node;
            node = node->next;
        }
        if (node == nullptr)
            return prev;
        Node* save_next = node->next;

        // set pointer
        Node* child = node->child;
        child->prev = node;
        node->next = child;
        node->child = nullptr;
        Node* child_last = _flatten(child);
        if (save_next) {
			child_last->next = save_next;
            save_next->prev = child_last;
            return _flatten(save_next);
        } else {
            return child_last;
        }
    }
};