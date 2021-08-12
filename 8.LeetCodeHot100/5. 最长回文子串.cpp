#include "leetcode_base.h"

class Solution {
   public:
    string longestPalindrome(string s) {
        if (s.empty())
            return "";

        int start = 0;
        int end = 0;
        int max_len = 0;

        // 奇数对称
        for (int mid = 0; mid < s.size(); mid++) {
            for (int i = 0;
                 i <= s.size() / 2 && mid - i >= 0 && mid + i < s.size(); i++) {
                if (s[mid - i] == s[mid + i]) {
                    if (max_len < 2 * i + 1) {
                        max_len = 2 * i + 1;
                        start = mid - i;
                        end = mid + i;
                    }
                } else {
                    break;
                }
            }
        }
        // 偶数对称
        for (int mid = 0; mid + 1 < s.size(); mid++) {
            for (int i = 0;
                 i <= s.size() / 2 && mid - i >= 0 && mid + 1 + i < s.size();
                 i++) {
                if (s[mid] == s[mid + 1] && s[mid - i] == s[mid + i + 1]) {
                    if (max_len < 2 * i + 2) {
                        max_len = 2 * i + 2;
                        start = mid - i;
                        end = mid + i + 1;
                    }
                }else{
					break;
				}
            }
        }
        return s.substr(start, end - start + 1);
    }
};

int main() {
    Solution sol;
    // cout << sol.longestPalindrome("babad") << endl;
    // cout << sol.longestPalindrome("cbbd") << endl;
    // cout << sol.longestPalindrome("a") << endl;
    // cout << sol.longestPalindrome("ac") << endl;
    // cout << sol.longestPalindrome("aacabdkacaa") << endl;
    cout << sol.longestPalindrome("aaaa") << endl;
    return 0;
}