#include "leetcode_base.h"

class Solution {
   public:
    int longestCommonSubstring(string text1, string text2) {
        vector<vector<int>> dp(text1.size() + 1,
                               vector<int>(text2.size() + 1, 0));
        int largest_len = 0;

        for (int i = 1; i <= text1.size(); i++) {
            for (int j = 1; j <= text2.size(); j++) {
                if (text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = 0;
                }
                largest_len = max(largest_len, dp[i][j]);
            }
        }

        return largest_len;
    }
};

int main() {
    Solution sol;
    cout << sol.longestCommonSubstring("abccbdad", "cba") << endl;
    return 0;
}