#include "leetcode_base.h"

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
    ListNode* detectCycle(ListNode* head) {
        if (!head)
            return nullptr;

        ListNode* fast = head;
        ListNode* slow = head;
        while (fast->next && fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
            if (slow == fast)
                break;
        }
        if (fast->next == nullptr || fast->next->next == nullptr)
            return nullptr;

        slow = head;
        while (slow != fast) {
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }
};

int main() {
    ListNode* head = createList();
    ListNode* tail = head;
    while (tail->next) {
        tail = tail->next;
    }
	tail->next = head->next;
	Solution sol;
	cout << sol.detectCycle(head)->val << endl;

    return 0;
}