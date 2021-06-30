#include "leetcode_base.h"

/*
 * @lc app=leetcode.cn id=150 lang=cpp
 *
 * [150] 逆波兰表达式求值
 */

// @lc code=start
class Solution
{
public:
    int evalRPN(vector<string> &tokens)
    {
        stack<int> stk;
        for (const string &s : tokens)
        {
            if (s.size() >= 2 || (s.size() == 1 && s[0] >= '0' && s[0] <= '9'))
            {
                int value = atoi(s.c_str());
                stk.push(value);
            }
            else
            {
                assert(s.size() == 1);
                calc(&stk, s.front());
            }
        }
        assert(!stk.empty());
        return stk.top();
    }

private:
    void calc(stack<int> *stk, char cur_op)
    {
        assert(!stk->empty());
        int num2 = stk->top();
        stk->pop();
        assert(!stk->empty());
        int num1 = stk->top();
        stk->pop();

        switch (cur_op)
        {
        case '+':
            stk->push(num1 + num2);
            break;

        case '-':
            stk->push(num1 - num2);
            break;

        case '*':
            stk->push(num1 * num2);
            break;

        case '/':
            assert(num2 != 0);
            stk->push(num1 / num2);
            break;

        default:
            assert(1 == 0);
        }
    }
};
// @lc code=end

int main()
{
    Solution sol;
    {
        vector<string> tokens = {"2", "1", "+", "3", "*"};
        cout << sol.evalRPN(tokens) << endl;
    }
    {
        vector<string> tokens = {"4", "13", "5", "/", "+"};
        cout << sol.evalRPN(tokens) << endl;
    }
    {
        vector<string> tokens = {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
        cout << sol.evalRPN(tokens) << endl;
    }
    return 0;
}