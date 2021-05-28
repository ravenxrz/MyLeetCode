//
// Created by raven on 5/28/21.
//

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
  ListNode *mergeInBetween(ListNode *list1, int a, int b, ListNode *list2) {
    ListNode *tail1 = list1;
    // move tail1 to a^th -1
    for (int i = 0; i < a - 1; i++) {
      tail1 = tail1->next;
    }
    ListNode *save_next = tail1->next;
    tail1->next = list2;
    tail1 = save_next;

    // move tial1 to b^th + 1
    for (int i = 0; i < b - a + 1; i++) {
      tail1 = tail1->next;
    }

    // move tail2 to the last node of list2
    ListNode *tail2 = list2;
    while (tail2->next) {
      tail2 = tail2->next;
    }
    // concate two lists
    tail2->next = tail1;
    return list1;
  }
};
