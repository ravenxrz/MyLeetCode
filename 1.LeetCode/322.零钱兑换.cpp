/*
 * @lc app=leetcode.cn id=322 lang=cpp
 *
 * [322] 零钱兑换
 */

#include <vector>
#include <cstring>
using namespace std;

// @lc code=start
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int *dp = new int[amount+1];
        memset(dp, -1, sizeof(int) * (amount + 1));
        dp[0] = 0;

        for (int i = 1; i <= amount;i++){
            int min = 0x7fffffff;
            for (int j = 0; j < coins.size(); j++)
            {
                if(i == coins[j]){
                    min = 1;
                    break;
                }

                if(i > coins[j]){       // 保证可以采用第j个面值
                    if(dp[i - coins[j]] != -1 &&    // 保证可采用前面的最优解
                        min > dp[coins[j]] + dp[i - coins[j]]){ // 使用当前面值后，可以得到更少的钞票
                        min = dp[coins[j]] + dp[i - coins[j]];
                    }
                }
            }
            dp[i] = min == 0x7fffffff ? -1 : min;
        }

        int ret = dp[amount];
        delete []dp;
        dp = nullptr;
        return ret;
    }
};
// @lc code=end

