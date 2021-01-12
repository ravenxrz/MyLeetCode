/*
 * 题目：请实现一个函数，把字符串中的每个空格替换成"%20".例如，
 * 输入“ We are happy”，则输出“We%20are%20 happy.”.
 *
 * inputs:
 * [
      [1,   4,  7, 11, 15],
      [2,   5,  8, 12, 19],
      [3,   6,  9, 16, 22],
      [10, 13, 14, 17, 24],
      [18, 21, 23, 26, 30]
    ]
 */
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    string replaceSpace(string s)
    {
        if (s.empty()) return "";
        // 计算空格数
        int cnt = 0;
        for (auto c : s) {
            if (c == ' ') {
                cnt++;
            }
        }
        // 设置两个下标
        int p1 = s.length() - 1;
        s.resize(s.length() + 2 * cnt);
        int p2 = s.length() - 1;
        while (p1 != -1) {
            if (s[p1] == ' ') {
                s[p2] = '0';
                s[p2 - 1] = '2';
                s[p2 - 2] = '%';
                p2 -= 3;
            } else {
                s[p2] = s[p1];
                p2--;
            }
            p1--;
        }
        return s;
    }
};

void test(string s)
{
    static Solution sol;
    cout << sol.replaceSpace(s) << endl;
}

int main()
{
    Solution sol;
    
    // empty
    {
        test("");
    }
    
    // no sapce
    {
        test("123");
    }
    
    // has sapce
    {
        test("1 2 3");
        
        test(" 1 2 3 ");
    }
    
    return 0;
}
