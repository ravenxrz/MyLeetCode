class Solution {
   public:
    bool checkValidString(string s) {
        stack<int> stk1;  // stores left brace idx
        stack<int> stk2;  // stores star idx
        int star_cnt = 0;
        for (int i = 0; i < s.size(); i++) {
            switch (s[i]) {
                case '(':
                    stk1.push(i);
                    break;
                case ')':
                    if (stk1.empty()) {
                        if (stk2.empty())
                            return false;
                        else
                            stk2.pop();
                    } else {
                        stk1.pop();
                    }
                    break;
                case '*':
                    stk2.push(i);
                    break;
            }
        }
        if (stk2.size() < stk1.size())
            return false;
        while (!stk1.empty()) {
          int brace_idx = stk1.top();
          int star_idx = stk2.top();
          if(star_idx < brace_idx) return false;
          stk1.pop();
          stk2.pop();
        }
        return true;
    }
};