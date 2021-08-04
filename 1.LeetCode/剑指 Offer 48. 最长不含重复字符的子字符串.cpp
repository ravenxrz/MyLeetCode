#include "leetcode_base.h"

class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty())
            return 0;
        int left = 0;
        int right = 0;
        unordered_set<char> uset;
        int max_len = 0;

        while (right < s.size()) {
            if (uset.count(s[right]) == 0) {
                uset.insert(s[right]);
                max_len = max(max_len, right - left + 1);
            } else {
                while (left < right && s[left] != s[right]) {
                    uset.erase(s[left]);
                    left++;
                }
                if (left != right) {
                    left++;
                }
            }
            right++;
        }

        return max_len;
    }
};

int main() {
    Solution sol;
    cout << sol.lengthOfLongestSubstring("abcabcbb") << endl;
    cout << sol.lengthOfLongestSubstring("bbbb") << endl;
    cout << sol.lengthOfLongestSubstring("pwwkew") << endl;
    return 0;
}