/**
 * 请实现一个函数用来匹配包含'. '和'*'的正则表达式。
 * 模式中的字符'.'表示任意一个字符，而'*'表示它前面的字符可以出现任意次（含0次）。
 * 在本题中，匹配是指字符串的所有字符匹配整个模式。例如，字符串"aaa"与模式"a.a"和"ab*ac*a"匹配，但与"aa.a"和"ab*a"均不匹配。
 */

#include <string>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p)
    {
        // bound check
        if (s.empty() || p.empty()) return false;
        
        if (p[0] == '*') return false;
        
        return check(s, 0, p, 0);
    }

private:
    bool check(const string &s, int s_idx, const string &p, int p_idx)
    {
        if (s_idx == s.size() && p_idx == p.size()) { // 都移动到最后一位了
            return true;
        } else if (s_idx != s.size() && p_idx == p.size()) {
            return false;
        } else if (s_idx == s.size() && p_idx != p.size()) {
            // only 1 case will return true. that is .*
            if (p[p.size() - 1] != '*') return false;
            
            for (; p_idx + 1 < p.size(); p_idx += 2) {
                if (p[p_idx] != '.' || p[p_idx + 1] != '*') return false;
            }
            return true;
        } else { // s_idx != s.size() && p_idx != p.size()
            if (p_idx + 1 < p.size()) {
                if (p[p_idx + 1] == '*') { // regex match
                    if (p[p_idx] == '.' || s[s_idx] == p[p_idx]) {
                        // s 移动一位，p不移动
                        if (check(s, s_idx + 1, p, p_idx)) {
                            return true;
                        }
                        // s 移动一位，p移动两位
                        return check(s, s_idx + 1, p, p_idx + 2);
                    } else {
                        return false;
                    }
                } else { // normal match
                    if (s[s_idx] != p[p_idx]) return false;
                    return check(s, s_idx + 1, p, p_idx + 1;)
                }
            } else {
                // p_idx is the last index
                if (p[p_idx] == '.' || s[s_idx] == p[p_idx]) {
                    return check(s, s_idx + 1, p, p_idx + 1);
                } else {
                    return false;
                }
            }
        }
    }
};


int main()
{
    return 0;
}