class Solution {
public:
  bool validateStackSequences(const vector<int> &pushed,
                              const vector<int> &popped) {
    if (pushed.size() != popped.size())
      return false;
    else if (pushed.empty())
      return true;
    // size equals and not empty
    stack<int> stk;
    int push_idx = 0;
    for (int i = 0; i < popped.size(); i++) {
      while (stk.empty() || stk.top() != popped[i]) {
        if (push_idx >= pushed.size())
          return false;
        stk.push(pushed[push_idx++]);
      }
      // when code runs here, stk.top() = popped[i]
      stk.pop();
    }
    return true;
  }
};
