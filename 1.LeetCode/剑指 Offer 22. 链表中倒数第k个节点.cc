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
    ListNode* getKthFromEnd(ListNode* head, int k) {
        if (!head)
            return nullptr;
        ListNode dumpyHead(0);
        dumpyHead.next = head;

        ListNode* pre_go = &dumpyHead;
        ListNode* now_go = &dumpyHead;

        // Let "pre_go"	move forward k steps first
        for (int i = 0; i < k && pre_go; i++) {
            pre_go = pre_go->next;
        }
        assert(pre_go);

        // Let "now_go" move forward with "pre_go" util "pre_go" reaches the
        // "nullptr"
        while (pre_go) {
            pre_go = pre_go->next;
            now_go = now_go->next;
        }
        return now_go;
    }
};

int main() {
    Solution sol;
    ListNode* head = createList();
    cout << sol.getKthFromEnd(head, 3)->val << endl;
    return 0;
}