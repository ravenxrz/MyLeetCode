#include <iostream>
using namespace std;
/*
 * @lc app=leetcode.cn id=707 lang=cpp
 *
 * [707] 设计链表
 */

// @lc code=start
class MyLinkedList {
public:
  /** Initialize your data structure here. */
  MyLinkedList() : len(0), tail(&dummy_head) {}

  /** Get the value of the index-th node in the linked list. If the index is
   * invalid, return -1. */
  int get(int index) {
    if (index < 0 || index >= len)
      return -1;
    ListNode *p = nullptr;
    for (p = dummy_head.next; index; p = p->next) {
      index--;
    }
    return p->val;
  }

  /** Add a node of value val before the first element of the linked list. After
   * the insertion, the new node will be the first node of the linked list. */
  void addAtHead(int val) {
    ListNode *node = new ListNode;
    node->val = val;
    node->next = dummy_head.next;
    dummy_head.next = node;
    if (tail == &dummy_head)
      tail = node;
    len++;
  }

  /** Append a node of value val to the last element of the linked list. */
  void addAtTail(int val) {
    ListNode *node = new ListNode;
    node->val = val;
    tail->next = node;
    tail = node;
    len++;
  }

  /** Add a node of value val before the index-th node in the linked list. If
   * index equals to the length of linked list, the node will be appended to the
   * end of linked list. If index is greater than the length, the node will not
   * be inserted. */
  void addAtIndex(int index, int val) {
    if (index < 0 || index > len)
      return;
    if (len == index)
      addAtTail(val);
    else {
      ListNode *p = nullptr;
      for (p = &dummy_head; p && index; p = p->next) {
        index--;
      }
      ListNode *node = new ListNode;
      node->val = val;
      node->next = p->next;
      p->next = node;
      len++;
    }
  }

  /** Delete the index-th node in the linked list, if the index is valid. */
  void deleteAtIndex(int index) {
    if (index < 0 || index >= len)
      return;

    if (index == len - 1) {
      // Find prev pointer
      ListNode *tail_prev = nullptr;
      for (tail_prev = &dummy_head; tail_prev->next != tail;
           tail_prev = tail_prev->next)
        ;
      // TODO:
      delete tail;
      tail_prev->next = nullptr;
      tail = tail_prev;
    } else {
      ListNode *p = nullptr;
      for (p = &dummy_head; p && index; p = p->next) {
        index--;
      }
      ListNode *deleted_node = p->next;
      p->next = p->next->next;
      delete deleted_node;
    }
    len--;
  }

private:
  struct ListNode {
    int val{0};
    ListNode *next{nullptr};
  };

  ListNode dummy_head;
  ListNode *tail;
  int len;
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
// @lc code=end

int main() {

  MyLinkedList list;
  list.addAtHead(1);
  list.deleteAtIndex(0);
  return 0;
}