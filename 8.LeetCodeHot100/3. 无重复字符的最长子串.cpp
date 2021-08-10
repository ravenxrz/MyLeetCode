#include "leetcode_base.h"

class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        if (s.empty())
            return 0;
        int left = 0;
        int right = 0;
        int max_length = 0;
        unordered_set<int> uset;
        while (right < s.size()) {
            if (!uset.count(s[right])) {
                uset.insert(s[right]);
            } else {
                while (left < right && s[left] != s[right]) {
                    uset.erase(s[left]);
                    left++;
                }
                if (left < right) {
                    left++;
                }
            }
            right++;
            max_length = max(max_length, right - left);
        }
        return max_length;
    }
};

int main() {
    Solution sol;
    cout << sol.lengthOfLongestSubstring("bbbb") << endl;
    return 0;
}