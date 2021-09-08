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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode dumpyHead(0);
        ListNode* prev_start = &dumpyHead;
        ListNode* start = head;
        ListNode* end = start;
        dumpyHead.next = start;

        while (end) {
            for (int i = 0; i < k - 1 && end; i++) {
                end = end->next;
            }
            if (!end)
                break;

            ListNode* next_start = end->next;
            end->next = nullptr;  // 截断
            prev_start->next = reverseList(start, end);

            // start作为反转后的end
            start->next = next_start;
            prev_start = start;
            start = next_start;
            end = start;
        }

        return dumpyHead.next;
    }

   private:
    ListNode* reverseList(ListNode* start, ListNode* end) {
        ListNode* prev = nullptr;
        ListNode* cur = start;
        ListNode* next;
        while (cur) {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }
};

int main() {
    Solution sol;
    ListNode* head = createList();
    ListNode* p = sol.reverseKGroup(head, 3);
    while (p) {
        cout << p->val << ' ';
        p = p->next;
    }
    return 0;
}
