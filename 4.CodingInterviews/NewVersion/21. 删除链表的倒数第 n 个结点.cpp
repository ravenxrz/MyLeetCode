#include "leetcode_base.h"
using namespace std;

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
        ListNode dumpyHead(0);
        dumpyHead.next = head;

        ListNode* first = &dumpyHead;
        ListNode* second = first;
        for (int i = 0; i < n && first; i++) {
            first = first->next;
        }
        if (!first)
            return head;

        while (first->next) {
            second = second->next;
            first = first->next;
        }
        second->next = second->next->next;
        return dumpyHead.next;
    }
};

int main() {
    ListNode* head = createList();
    Solution sol;
    sol.removeNthFromEnd(head, 2);
    return 0;
}