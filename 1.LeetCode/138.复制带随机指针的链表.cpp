#include "leetcode_base.h"

class Node {
public:
  int val;
  Node *next;
  Node *random;

  Node(int _val) {
    val = _val;
    next = NULL;
    random = NULL;
  }
};

/*
 * @lc app=leetcode.cn id=138 lang=cpp
 *
 * [138] 复制带随机指针的链表
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
  Node *copyRandomList(Node *head) {
    if (head == nullptr)
      return nullptr;
    std::unordered_map<Node *, Node *> node_map;
    // Copy "next" field of nodes to form a new list started by head
    // Copy head
    Node *new_head = new Node(head->val);
    Node *tail = new_head;
    node_map[head] = new_head;
    // Copy remaining nodes
    for (Node *p = head->next; p; p = p->next) {
      tail->next = new Node(p->val);
      tail = tail->next;
      node_map[p] = tail;
    }
    // Copy random node according to "node_map"
    Node *p1 = head;
    Node *p2 = new_head;
    while (p1 && p2) {
      if (p1->random) {
        p2->random = node_map[p1->random];
      }
      p1 = p1->next;
      p2 = p2->next;
    }
    return new_head;
  }
};
// @lc code=end
