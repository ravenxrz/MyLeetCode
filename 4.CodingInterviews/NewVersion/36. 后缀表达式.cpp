#include <bits/stdc++.h>
using namespace std;

class Solution {
   private:
    bool is_operator(const string& str) {
        if (str.size() != 1) {
            return false;
        }
        return str[0] == '+' || str[0] == '-' || str[0] == '/' || str[0] == '*';
    }

   public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        for (int i = 0; i < tokens.size(); i++) {
            if (is_operator(tokens[i])) {
                int num2 = stk.top();
                stk.pop();
                int num1 = stk.top();
                stk.pop();
                switch (tokens[i][0]) {
                    case '+':
                        stk.push(num1 + num2);
                        break;
                    case '-':
                        stk.push(num1 - num2);
                        break;
                    case '*':
                        stk.push(num1 * num2);
                        break;
                    case '/':
                        stk.push(num1 / num2);
                        break;
                }
            } else {
                stk.push(atoi(tokens[i].c_str()));
            }
        }
        return stk.top();
    }
};

int main() {
    Solution sol;
    {
        vector<string> tokens = {"2", "1", "+", "3", "*"};
        cout << sol.evalRPN(tokens) << endl;
    }
    {
        vector<string> tokens = {"4","13","5","/","+"};
        cout << sol.evalRPN(tokens) << endl;
    }
    return 0;
}