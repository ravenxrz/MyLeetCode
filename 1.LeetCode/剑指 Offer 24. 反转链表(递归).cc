class Solution {
public:
    ListNode *reverseList(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr) return head;
        return reverseRecursively(head);
    }

private:
    ListNode *reverseRecursively(ListNode *node)
    {
        if (node->next == nullptr) {
            return node;
        }
        ListNode *last = reverseRecursively(node->next);
        node->next->next = node;
        node->next = nullptr;
        return last;
    }
};
