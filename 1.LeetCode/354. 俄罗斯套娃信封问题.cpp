#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    static bool compare(const vector<int> &a, const vector<int> &b)
    {
        if (a[0] == b[0]) {
            return a[1] > b[1];
        }
        return a[0] < b[0];
    }

public:
    int maxEnvelopes(vector<vector<int>> &envelopes)
    {
        if (envelopes.empty()) return 0;
        sort(envelopes.begin(), envelopes.end(), compare);
        
        vector<int> dp(envelopes.size(), 1);
        int max_value = 1;
        for (int i = 1; i < dp.size(); i++) {
            int tmp_max = 1;
            for (int k = 0; k <= i - 1; ++k) {
                if (envelopes[i][1] > envelopes[k][1]) {
                    tmp_max = max(tmp_max, dp[k] + 1);
                }
            }
            dp[i] = tmp_max;
            max_value = max(max_value, dp[i]);
        }
        return max_value;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> env = {
            {1, 2},
            {2, 3},
            {3, 4},
            {4, 5},
            {5, 6},
            {5, 5},
            {6, 7},
            {7, 8}
    };
    cout << sol.maxEnvelopes(env) << '\n';
    return 0;
}
