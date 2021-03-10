//
// Created by Raven on 2021/3/9.
//

#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
    int max_value(const vector<int> &weights, const vector<int> &values, int capacity)
    {
        vector<vector<int>> dp(values.size() + 1, vector<int>(capacity + 1, 0));
        
        // calc
        for (int i = 1; i < values.size() + 1; ++i) {
            for (int j = 1; j < capacity + 1; ++j) {
                if (j >= weights[i-1]) {
                    dp[i][j] = max(dp[i - 1][j], dp[i-1][j - weights[i-1]] + values[i-1]);
                } else {
                    // could not put this
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[values.size()][capacity];
    }
};

int main()
{
    Solution sol;
    vector<int> weights{2, 1, 3, 2};
    vector<int> values{12, 10, 20, 15};
    cout << sol.max_value(weights, values, 5) << endl;
    
    return 0;
}

