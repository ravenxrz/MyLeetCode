#include "leetcode_base.h"

// Definition for a Node.
class Node {
public:
  int val;
  Node *prev;
  Node *next;
  Node *child;
  Node(int val) : val(val), prev(nullptr), next(nullptr), child(nullptr) {}
};

/*
 * @lc app=leetcode.cn id=430 lang=cpp
 *
 * [430] 扁平化多级双向链表
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
  Node *flatten(Node *head) {
    if (!head)
      return nullptr;
    flatten_core(head);
    return head;
  }

private:
  Node *flatten_core(Node *node) {
    if (!node->next && !node->child) {
      return node;
    }
    if (node->next && !node->child) {
      return flatten_core(node->next);
    } else if (!node->next && node->child) {
      node->next = node->child;
      node->child->prev = node;
      node->child = nullptr;
      return flatten_core(node->next);
    } else { // child && next
      Node *next_node = node->next;
      node->next = node->child;
      node->child->prev = node;
      node->child = nullptr;
      Node *last_node = flatten_core(node->next);
      last_node->next = next_node;
      next_node->prev = last_node;
      return flatten_core(next_node);
    }
  }
};
// @lc code=end

int main() {
  Node *head = new Node(7);
  head->next = new Node(8);
  head->next->next = new Node(9);
  head->next->next->next = new Node(10);

  Node *head2 = new Node(11);
  head2->next = new Node(12);

  // Concate two lists
  head->next->child = head2;

  // Solution
  Solution sol;
  sol.flatten(head);
  return 0;
}