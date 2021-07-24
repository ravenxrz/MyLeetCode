#include "leetcode_base.h"
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class MinStack {
public:
  /** initialize your data structure here. */
  MinStack() {}
  
  void push(int x) {
    stk.push(x);
    if (min_stk.empty() || x <= min_stk.top()) {
      min_stk.push(x);
    }
  }
  
  void pop() {
    assert(!min_stk.empty());
    if (min_stk.top() == stk.top()) {
      min_stk.pop();
    }
    stk.pop();
  }
  
  int top() { return stk.top(); }
  
  int min() {
    assert(!min_stk.empty());
    return min_stk.top();
  }

private:
  stack<int> stk;
  stack<int> min_stk;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */
;

int main() { return 0; }
