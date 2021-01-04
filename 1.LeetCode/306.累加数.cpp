/*
 * @lc app=leetcode.cn id=306 lang=cpp
 *
 * [306] 累加数
 */
#include <string>
#include <iostream>

using namespace std;

// @lc code=start
/**
 * 处理溢出整数长度, 自定义两个字符串整数加法
 * @param str1
 * @param str2
 * @return
 */
string operator+(const string &str1, const string &str2)
{
    int i = str1.size() - 1;
    int j = str2.size() - 1;
    int rem = 0;
    string ret(max(str1.size(), str2.size()) + 1, '0');
    int idx = ret.size() - 1;
    int value = 0;
    
    while (i >= 0 && j >= 0) {
        value = str1[i] - '0' + str2[j] - '0' + rem;
        rem = value / 10;
        ret[idx] = value % 10 + '0';
        i--;
        j--;
        idx--;
    }
    
    while (i >= 0) {
        value = str1[i] - '0' + rem;
        rem = value / 10;
        ret[idx] = value % 10 + '0';
        i--;
        idx--;
    }
    while (j >= 0) {
        value = str2[j] - '0' + rem;
        rem = value / 10;
        ret[idx] = value % 10 + '0';
        j--;
        idx--;
    }
    // 多余余数
    if (rem != 0) {
        ret[idx] = rem + '0';
    }
    
    // 去除前导0
    if (ret[0] == '0') {
        ret.erase(0, 1);
    }
    return ret;
}

class Solution {
public:
    bool isAdditiveNumber(string num)
    {
        if (num.size() < 3) return false;
        return backtrace(num, 0, 0, 0, 0, 0);
    }
    
    bool backtrace(const string &num, int cur, int f, int len1, int s, int len2)
    {
        if (cur >= num.size()) {
            return true;
        }
        
        // 第一个字符串
        if (len1 == 0) {        // 这里应该可以直接优化
            for (int len = 1; len < num.size() - cur; len++) {
                if (backtrace(num, cur + len, cur, len, s, len2)) {
                    return true;
                }
            }
            return false;
        }
        // 第二个字符串
        if (len2 == 0) {
            for (int len = 1; len < num.size() - cur; len++) {
                if (backtrace(num, cur + len, f, len1, cur, len)) {
                    return true;
                }
                
            }
            return false;
        }
        // 比较
        const string &str1 = num.substr(f, len1);
        const string &str2 = num.substr(s, len2);
        // 去除 0xx 情况
        if ( (str1.at(0) == '0' && str1.at(str1.size() - 1) != '0') ||
                (str2.at(0) == '0' && str2.at(str2.size() - 1) != '0')) {
            return false;
        }
        const string &cmp = ::operator+(str1, str2);
        if (cmp != num.substr(cur, cmp.size())) {
            return false;
        }
        return backtrace(num, cur + cmp.size(), s, len2, cur, cmp.size());
    }
    
};

// @lc code=end
int main()
{
//    cout << ::operator+("1", "9") << endl;
    Solution sol;
    cout << sol.isAdditiveNumber("199001200");
    return 0;
}

