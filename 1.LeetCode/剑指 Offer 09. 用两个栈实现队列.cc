#include "leetcode_base.h"

class CQueue {
public:
  CQueue() {
  
  }
  
  void appendTail(int value) {
    stk1.push(value);
  }
  
  int deleteHead() {
    if(stk1.empty() && stk2.empty()){
      return -1;
    }
    if(stk2.empty()){
      while(!stk1.empty()){
        stk2.push(stk1.top());
        stk1.pop();
      }
    }
    assert(!stk2.empty());
    int value = stk2.top();
    stk2.pop();
    return value;
  }

private:
  stack<int> stk1;
  stack<int> stk2;
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */

int main() {
  return 0;
}
