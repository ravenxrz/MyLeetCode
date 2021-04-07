#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2)
    {
        if (word1.empty()) return word2.size();
        if (word2.empty()) return word1.size();
        
        vector<vector<int>> dp(word1.size() + 1, vector<int>(word2.size() + 1, 0x7fffffff));
        // base
        for (int i = 0; i < dp.size(); ++i) {
            dp[i][0] = i;
        }
        for (int j = 0; j < dp[0].size(); ++j) {
            dp[0][j] = j;
        }
        // core
        for (int i = 1; i < dp.size(); i++) {
            for (int j = 1; j < dp[0].size(); ++j) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = min(dp[i - 1][j] + 1, dp[i][j - 1] + 1);
                }
            }
        }
        return dp[word1.size()][word2.size()];
    }
};

int main()
{
    Solution sol;
    {
        cout << sol.minDistance("sea","eat") << '\n';
    }
    
    return 0;
}
