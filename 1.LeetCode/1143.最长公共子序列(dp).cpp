#include "leetcode_base.h"

class Solution {
   public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text2.size() + 1,
                               vector<int>(text1.size() + 1, 0));
        for (int i = 1; i <= text2.size(); i++) {
            for (int j = 1; j <= text1.size(); j++) {
                if (text1[j - 1] == text2[i - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[text2.size()][text1.size()];
    }
};

int main() {
    Solution sol;
    { cout << sol.longestCommonSubsequence("abcde", "ace") << endl; }
    return 0;
}