
ListNode* reverse_list(ListNode* node) {
    if (node->next == nullptr)
        return node;
    ListNode* last = reverse_list(node->next);
    node->next->next = node;
    node->next = nullptr;
    return last;
}