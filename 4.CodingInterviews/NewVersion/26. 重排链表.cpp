#include "leetcode_base.h"
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
    void reorderList(ListNode* head) {
        if (!head)
            return;
        ListNode *slow = head, *fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode dumpyHead(0);
        dumpyHead.next = reverseList(slow->next);
        slow->next = nullptr;

        /* Now we get two lists: head and dumpyHead */
        ListNode ansHead(0);
        ListNode* tail = &ansHead;
        bool turn = true;
        ListNode* p1 = head;
        ListNode* p2 = dumpyHead.next;
        while (p1 && p2) {
            if (turn) {
                tail->next = p1;
                tail = p1;
                p1 = p1->next;
            } else {
                tail->next = p2;
                tail = p2;
                p2 = p2->next;
            }
            turn = !turn;
        }
        if (p1) {
            tail->next = p1;
        }
        if (p2) {
            tail->next = p2;
        }
    }

   private:
    ListNode* reverseList(ListNode* node) {
        if (!node || !node->next)
            return node;
        ListNode* last_node = reverseList(node->next);
        node->next->next = node;
        node->next = nullptr;
        return last_node;
    }
};

int main() {
    ListNode* head = createList();
    Solution sol;
    sol.reorderList(head);
	ListNode *p = head;
    while (p) {
        cout << p->val << ' ';
        p = p->next;
    }

    return 0;
}
