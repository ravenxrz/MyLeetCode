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
    bool isPalindrome(ListNode* head) {
        if (!head)
            return true;
        ListNode *slow = head, *fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* p1 = head;
        ListNode* p2 = reverseList(slow->next);
        while (p1 && p2) {
            if (p1->val != p2->val)
                return false;
            p1 = p1->next;
            p2 = p2->next;
        }
        return true;
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
    return 0;
}