#include <iostream>
#include <cstring>

using namespace std;

class Solution {
public:
    int strToInt(string str)
    {
        // empty case
        if (str.empty()) return 0;
        // 去除前导space
        int i = 0;
        while (i < str.size() && isspace(str[i])) i++;
        // 全是space
        if (i == str.size()) return 0;
        
        // 判断是否存在正负号
        // 正号
        if (str[i] == '+') {
            i++;
        }
        bool is_negative = false;
        if (str[i] == '-') {
            is_negative = true;
            i++;
        }
        // 开头是否是正常字符
        if (!isdigit(str[i])) return 0;
        
        // 下面是正常转换
        // 考虑int溢出
        long long num = 0;
        for (; i < str.size(); i++) {
            if (!isdigit(str[i])) break;
            num = num * 10 + (str[i] - '0');
        }
        if(is_negative) {
            num = -num;
            if(num < INT32_MIN)
        }
        
        
        return num;
    }
};
