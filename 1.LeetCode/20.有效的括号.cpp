/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */
#include <iostream>
#include <stack>
#include <string>
using namespace std;

// @lc code=start
class Solution
{
public:
    bool isValid(string s)
    {
        if (s.empty())
            return true;

        stack<char> stk;
        stk.push(s.at(0));

        for (int i = 1; i < s.size(); i++)
        {
            const char &c = s.at(i);

            switch (c)
            {
            case '(':
                stk.push(c);
                break;
            case '{':
                stk.push(c);
                break;
            case '[':
                stk.push(c);
                break;
            case ')':
                if (!stk.empty() && stk.top() == '(')
                {
                    stk.pop();
                }
                else
                {
                    return false;
                }
                break;
            case '}':
                if (!stk.empty() && stk.top() == '{')
                {
                    stk.pop();
                }
                else
                {
                    return false;
                }
                break;
            case ']':
                if (!stk.empty() && stk.top() == '[')
                {
                    stk.pop();
                }
                else
                {
                    return false;
                }
                break;
            default:
                break;
            }
        }
        return stk.empty();
    }
};
// @lc code=end

int main(){
    Solution sol;
    cout << sol.isValid("(){}}{") << endl;
}