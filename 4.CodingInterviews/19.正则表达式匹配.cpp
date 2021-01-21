/**
 * 请实现一个函数用来匹配包含'. '和'*'的正则表达式。
 * 模式中的字符'.'表示任意一个字符，而'*'表示它前面的字符可以出现任意次（含0次）。
 * 在本题中，匹配是指字符串的所有字符匹配整个模式。例如，字符串"aaa"与模式"a.a"和"ab*ac*a"匹配，但与"aa.a"和"ab*a"均不匹配。
 */

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p)
    {
        return check(s, 0, p, 0);
    }

private:
    bool check(const string &s, int s_idx, const string &p, int p_idx)
    {
        // s和p都匹配到最后
        if (s_idx == s.size() && p_idx == p.size()) return true;
        
        // s不到最后，p到最后
        if (s_idx != s.size() && p_idx == p.size()) return false;
        
        // s到最后，p不到最后
        if (s_idx == s.size() && p_idx != p.size()) {
            // 这种情况，只有 p的后半段全为 x* 这种情况
            if (p[p.size() - 1] != '*') return false;
            for (int i = p_idx; i + 1 < p.size(); i += 2) {
                if (p[i + 1] != '*') return false;
            }
            return true;
        }
        
        // s 不到最后，p不到最后
        if (p_idx + 1 < p.size()) {
            // 分两种情况
            if (p[p_idx + 1] == '*') {
                if (p[p_idx] == '.' || p[p_idx] == s[s_idx]) {
                    return check(s, s_idx + 1, p, p_idx)  /* p 不动， s+1  */
                           || check(s, s_idx + 1, p, p_idx + 2) /* p + 2， s+1 */
                           || check(s, s_idx, p, p_idx + 2);        /* p +2 ， s不动 */
                } else {
                    /* 忽略当前p字符 */
                    return check(s, s_idx, p, p_idx + 2);
                }
            } else {
                if (p[p_idx] == '.' || p[p_idx] == s[s_idx]) {
                    return check(s, s_idx + 1, p, p_idx + 1);
                } else {
                    return false;
                }
            }
        } else { // p到最后一个字符
            if (p[p_idx] == '.' || s[s_idx] == p[p_idx])
                return check(s, s_idx + 1, p, p_idx + 1);
            else
                return false;
        }
    }
};


int main()
{
    Solution sol;
    {
        // empty s
        cout << sol.isMatch("", "aa") << endl;
        // empty p
        cout << sol.isMatch("aa", "") << endl;
        
        // normal match (no regex)
        cout << sol.isMatch("aa", "aa") << endl;
        
        // . match
        cout << sol.isMatch("aa", ".a") << endl;
        // . match
        cout << sol.isMatch("aa", "a.a") << endl;
        
        // * match
        cout << sol.isMatch("aa", "a*") << endl;
        
        // .* match
        cout << sol.isMatch("aabcd", "a.*") << endl;
        
        cout << sol.isMatch("aab", "c*a*b") << endl;
        
        // "mississippi"
        //"mis*is*p*."
        
        cout << sol.isMatch("mississippi", "mis*is*p*.") << endl;
        
        cout << sol.isMatch("a", "ab*") << endl;
        
        cout << sol.isMatch("bbba", ".*a*a") << endl;
        
        cout << sol.isMatch("", ".*") << endl;
        
        cout << sol.isMatch("ab", ".*c") << endl;
    }
    return 0;
}
