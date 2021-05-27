//
// Created by raven on 5/27/21.
//
class Solution {
public:
  ListNode *sortList(ListNode *head) {
    int len = 0;
    ListNode *p = head;
    while (p) { // Get length of list
      ++len;
      p = p->next;
    }

    ListNode dummyHead(0);
    dummyHead.next = head;
    for (int delta = 1; delta <= len; delta <<= 1) {
      ListNode *pre_head = &dummyHead;
      ListNode *left = pre_head->next;
      while (left) {
        ListNode *right = cut(left, delta);
        ListNode *next_left = cut(right, delta);
        ListNode *tmp_head = merge(left, right);
        pre_head->next = tmp_head;
        pre_head = tmp_head;
        while (pre_head->next) {
          pre_head = pre_head->next;
        }
        left = next_left;
      }
    }
    return dummyHead.next;
  }

private:
  // Cut list stating with head to hold n nodes.
  // Then return remaining list head
  ListNode *cut(ListNode *head, int n) {
    ListNode *tail = head;
    while (--n && tail) {
      tail = tail->next;
    }
    if (tail == nullptr)
      return nullptr;
    ListNode *ret = tail->next;
    tail->next = nullptr;
    return ret;
  }

  ListNode *merge(ListNode *head1, ListNode *head2) {
    ListNode head(0);
    ListNode *tail = &head;

    while (head1 && head2) {
      if (head1->val <= head2->val) {
        tail->next = head1;
        tail = head1;
        head1 = head1->next;
      } else {
        tail->next = head2;
        tail = head2;
        head2 = head2->next;
      }
    }

    if (head1) {
      tail->next = head1;
    }
    if (head2) {
      tail->next = head2;
    }
    return head.next;
  }
};
