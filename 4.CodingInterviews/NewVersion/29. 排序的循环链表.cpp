class Solution {
   public:
    Node* insert(Node* head, int insertVal) {
        /* Assume there is no nullptr pointer that we will go through */
        Node* node = new Node(insertVal);
        node->next = node;
        if (!head)
            return node;
        if (head == head->next) {
            node->next = head;
            head->next = node;
            return head;
        } else {
            // Find the head
            Node* prev = head;
            Node* cur = head->next;
            while (cur != head) {
                if (cur->val >= prev->val) {
                    prev = cur;
                    cur = cur->next;
                } else {
                    break;
                }
            }
            Node* rhead = cur;

            do {
                if (cur->val >= insertVal) {
                    break;
                } else {
                    prev = cur;
                    cur = cur->next;
                }
            } while (cur != rhead);
            prev->next = node;
            node->next = cur;
        }
        return head;
    }
};