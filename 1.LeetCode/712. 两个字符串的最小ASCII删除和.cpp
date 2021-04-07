class Solution {
public:
    int minimumDeleteSum(string s1, string s2)
    {
        if (s1.empty()) return accumulate(s2.begin(), s2.end(), 0);
        if (s2.empty()) return accumulate(s1.begin(), s1.end(), 0);
        
        vector <vector<int>> dp(s1.size() + 1, vector<int>(s2.size() + 1, 0x7fffffff));
        dp[0][0] = 0;
        // base
        int base = 0;
        for (int i = 1; i < dp.size(); ++i) {
            base += s1[i - 1];
            dp[i][0] = base;
        }
        base = 0;
        for (int j = 1; j < dp[0].size(); ++j) {
            base += s2[j - 1];
            dp[0][j] = base;
        }
        // core
        for (int i = 1; i < dp.size(); ++i) {
            for (int j = 1; j < dp[0].size(); ++j) {
                if (s1[i - 1] == s2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = min(dp[i - 1][j] + s1[i - 1], dp[i][j - 1] + s2[j - 1]);
                }
            }
        }
        return dp[s1.size()][s2.size()];
    }
};

