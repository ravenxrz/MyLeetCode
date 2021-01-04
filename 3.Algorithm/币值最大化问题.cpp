/*
 * @lc app=leetcode.cn id=946 lang=cpp
 *
 * [946] 验证栈序列
 */
#include <algorithm>
#include <iostream>

using namespace std;

// @lc code=end
int main()
{
    int coins[] = {1, 2, 3, 5, 4, 1, 6, 8, 10};
    const int len = sizeof(coins) / sizeof(int);
    int dp[len + 1];
    dp[0] = 0;
    dp[1] = coins[0];
    
    for (int i = 2; i <= len; i++) {
        dp[i] = max(dp[i - 1], dp[i - 2] + coins[i - 1]);
    }
    cout << "max:" << dp[len];
    
    return 0;
}

