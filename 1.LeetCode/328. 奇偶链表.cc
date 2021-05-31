//
// Created by raven on 5/31/21.
//
class Solution {
public:
  ListNode *partition(ListNode *head, int x) {
    ListNode head1(0);
    ListNode *tail = &head1;
    ListNode head2(0);

    for (ListNode *p = head; p;) {
      if (p->val < x) {
        tail->next = p;
        tail = p;
        p = p->next;
      } else {
        ListNode *save_next = p->next;
        p->next = head2.next;
        head2.next = p;
        p = save_next;
      }
    }
    tail->next = head2.next;
    return head1.next;
  }
};
