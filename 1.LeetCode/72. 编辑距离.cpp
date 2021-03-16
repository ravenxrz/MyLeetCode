#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int minDistance(string word1, string word2)
    {
        const int len1 = word1.size();
        const int len2 = word2.size();
        vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0x7fffffff));
        // base
        for (int i = 0; i <= len1; i++) {
            dp[i][0] = i;
        }
        for (int j = 0; j <= len2; j++) {
            dp[0][j] = j;
        }
        // core
        for (int i = 1; i <= len1; i++) {
            for (int j = 1; j <= len2; j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = min({
                                           dp[i - 1][j - 1],// replace
                                           dp[i - 1][j],   // delete
                                           dp[i][j - 1]      // add
                                   }) + 1;
                }
            }
        }
        return dp[len1][len2];
    }
};

int main()
{
    Solution sol;
    cout << sol.minDistance("horse", "ros") << '\n';
    cout << sol.minDistance("intention", "execution") << '\n';
    return 0;
}
