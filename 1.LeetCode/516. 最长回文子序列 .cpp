#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int longestPalindromeSubseq(string s)
    {
        if (s.empty()) return 0;
        vector<int> dp(s.size(), 1);
        
        for (int i = s.size() - 2; i >= 0; --i) {
            int pre = 0;
            for (int j = i + 1; j < s.size(); j++) {
                int tmp = dp[j];
                if (s[i] == s[j]) {
                    dp[j] = pre + 2;
                } else {
                    dp[j] = max(dp[j - 1], dp[j]);
                }
                pre = tmp;
            }
        }
        return dp[s.size()-1];
    }
};

int main()
{
    Solution sol;
    cout << sol.longestPalindromeSubseq("bbbab") << '\n';
    return 0;
}
