#include <bits/stdc++.h>
using namespace std;

class Solution {
    /* 如果op1的优先级大于等于op2，返回true, 否则返回false */
    bool precedent(char op1, char op2) {
        if (op1 == '*' || op2 == '/')
            return true;
        if (op2 == '*' || op2 == '/')
            return false;
        return true;
    }

    long long operate(long long a, long long b, char op) {
        switch (op) {
            case '+':
                return a + b;
            case '-':
                return a - b;
            case '*':
                return a * b;
            case '/':
                return a / b;
            default:
                break;
        }
        return -1;
    }

    bool isoperator(char op) {
        return op == '+' || op == '-' || op == '*' || op == '/';
    }

   public:
    int calculate(string s) {
        stack<long long> numstk;
        stack<char> opstk;

        int i = 0;
        while (i < s.size()) {
            if (s[i] == '+' || s[i] == '-') {
                if (i == 0 || s[i - 1] == '(') {
                    s.insert(s.begin() + i, '0');
                }
            }
            i++;
        }

        for (int i = 0; i < s.size(); i++) {
            if (isspace(s[i]))
                continue;

            if (s[i] == '(') {
                opstk.push(s[i]);
            } else if (s[i] == ')') {
                /* process the numbers between (xxxx) */
                while (!opstk.empty() && opstk.top() != '(') {
                    assert(!opstk.empty());
                    char op = opstk.top();
                    opstk.pop();

                    long long num2 = numstk.top();
                    numstk.pop();
                    assert(!numstk.empty());
                    long long num1 = numstk.top();
                    numstk.pop();

                    numstk.push(operate(num1, num2, op));
                }
                assert(opstk.top() == '(');
                opstk.pop(); /* pop '(' */
            } else if (isdigit(s[i])) {
                /* process numbers */
                long long val = 0;
                while (i < s.size() && isdigit(s[i])) {
                    val = val * 10 + s[i] - '0';
                    i++;
                }
                i--; /* We need i-1 for the following "i++" */
                numstk.push(val);
            } else if (isoperator(s[i])) {
                /* operator */
                if (!opstk.empty() && opstk.top() != '(') {
                    char pre_op = opstk.top();
                    if (precedent(pre_op, s[i])) {
                        opstk.pop();
                        long long num2 = numstk.top();
                        numstk.pop();
                        long long num1 = numstk.top();
                        numstk.pop();
                        numstk.push(operate(num1, num2, pre_op));
                    }
                }
                opstk.push(s[i]);
            } else {
                cout << "Error!" << endl;
            }
        }

        while (!opstk.empty()) {
            char op = opstk.top();
            opstk.pop();
            long long num2 = numstk.top();
            numstk.pop();
            long long num1 = numstk.top();
            numstk.pop();
            numstk.push(operate(num1, num2, op));
        }

        return numstk.top();
    }
};

int main() {
    Solution sol;
    // cout << sol.calculate("1+ 2 +3") << endl;
    // cout << sol.calculate("1+2+3") << endl;
    // cout << sol.calculate("1+(2+3)") << endl;
    cout << sol.calculate("-1+(2+3)") << endl;
    cout << sol.calculate("-1+(-2+3)") << endl;
    cout << sol.calculate("-1+(+2+3)") << endl;
    cout << sol.calculate("-(1+(+2+3))") << endl;
    return 0;
}