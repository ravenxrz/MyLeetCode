#include <string>
#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;


class Solution {
public:
    string reverseWords(string s)
    {
        // remove trim characters
        int start = 0, end = s.size() - 1;
        while (start < s.size() && isspace(s[start])) start++;
        while (end >= 0 && isspace(s[end])) end--;
        s = s.substr(start, end - start + 1);
        if (s.empty()) return s;
        // reverse the whole sentence
        reverse(s.begin(), s.end());
        // 翻转单词
        int i = 0;
        while (i < s.size()) {
            int pre_i = i;
            while (i < s.size() && !isspace(s[i])) i++;
            reverse(s.begin() + pre_i, s.begin() + i);
            // 去除冗余空格
            while (i + 1 < s.size() && isspace(s[i + 1])) {
                s.erase(i,1);       // 另一种优化，找到连续空格位序列[start,end]
            }
            // move to next non-space character
            i++;
        }
        return s;
    }
};

int main()
{
    Solution sol;
    {
        cout << sol.reverseWords("the sky is blue") << endl;
        cout << sol.reverseWords("  hello world!  ") << endl;
        cout << sol.reverseWords("a good   example") << endl;
    }
    return 0;
}
