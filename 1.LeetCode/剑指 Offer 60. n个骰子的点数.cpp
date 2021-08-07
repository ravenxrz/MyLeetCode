#include "leetcode_base.h"

class Solution
{
public:
    vector<double> dicesProbability(int n)
    {
        // dp
        vector<vector<double>> dp(n + 1);
        // init
        for (int i = 1; i <= n; i++)
        {
            dp[i] = vector<double>(6 * n + 1, 0);
            dp[i][i] = 1;
            dp[i][6 * i] = 1;
        }
        // init n == 1
        for (int i = 1; i <= 6; i++)
        {
            dp[1][i] = 1;
        }
        // calc
        for (int i = 2; i <= n; i++) // f(i) = ?
        {
            for (int j = i + 1; j < i * 6; j++)
            {
                for (int k = 1; k <= 6; k++)
                {
                    dp[i][j] += dp[i - 1][j - k];
                }
            }
        }
        // print result
        for (int i = 0; i < dp[n].size(); i++)
        {
            cout << dp[n][i] << '\n';
        }
    }
};


int main()
{
	Solution sol;
	for(double val : sol.dicesProbability(1)){
		cout << val << ' ';
	}
	cout << endl;
	return 0;
}

/**
 * @brief 方法2： dfs超时
 *
 */
// class Solution {
//    private:
//     vector<double> dp;

//    public:
//     vector<double> dicesProbability(int n) {
//         dp.resize(n * 6, 0);
//         dfs(0, 0, n);
//         double sum = 0.0f;
//         for (double val : dp) {
//             sum += val;
//         }
//         for (double& val : dp) {
//             val /= sum;
//         }
//         // Find the first non-zero element
//         int idx = 0;
//         for (idx = 0; idx < dp.size() && dp[idx] == 0.0f; idx++)    //
//         这里的==0.0f是不准确的
//             ;
//         return vector<double>(dp.begin() + idx, dp.end());
//     }

//    private:
//     void dfs(int idx, int cur_sum, int n) {
//         if (idx == n) {
//             dp[cur_sum - 1] = dp[cur_sum - 1] + 1;
//             return;
//         }
//         for (int i = 1; i <= 6; i++) {
//             dfs(idx + 1, cur_sum + i, n);
//         }
//     }
// };