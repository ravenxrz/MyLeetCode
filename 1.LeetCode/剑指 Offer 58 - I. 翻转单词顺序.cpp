#include "leetcode_base.h"

class Solution {
   public:
    string reverseWords(string s) {
        // Remove space
        // Remove leading and trailing space
        int left = 0;
        while (left < s.size() && isspace(s[left]))
            left++;
        int right = s.size() - 1;
        while (right >= left && isspace(s[right]))
            right--;
        s = s.substr(left, right - left + 1);
        // Remove space characters in middle postion
        string str;
        int start = 0;
        int end = 0;
        while (end < s.size()) {
            assert(!isspace(s[start]));
            while (end < s.size() && !isspace(s[end])) {
                end++;
            }
            string tmp = s.substr(start, end - start);
            reverse(tmp.begin(), tmp.end());
            str.append(tmp).append(" ");
            // Find next word start
            start = end + 1;
            while (start < s.size() && isspace(s[start])) {
                start++;
            }
            end = start;
        }
        if (!str.empty()) {
            str.pop_back();  // Pop the last space
            reverse(str.begin(), str.end());
        }

        return str;
    }
};

int main() {
    Solution sol;
    cout << sol.reverseWords("the sky is blue") << endl;
    cout << sol.reverseWords("  ") << endl;
    cout << sol.reverseWords("    hello world   ") << endl;
    cout << sol.reverseWords("a good  example") << endl;
    cout << sol.reverseWords("   a  b") << endl;
    return 0;
}