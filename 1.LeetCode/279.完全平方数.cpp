/*
 * @lc app=leetcode.cn id=279 lang=cpp
 *
 * [279] 完全平方数
 */
#include <bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution {
public:
    int numSquares(int n)
    {
        if(n == 0) return 0;
        int *dp = new int[n+1];
        dp[0] = 0;
        
        for(int i = 1;i<=n;i++){
            // set
            dp[i] = dp[i-1] + 1;
            int max_base = sqrt(i);
            for(int base = 1;base<=max_base;base++){
               dp[i] = min(dp[i-base*base]+1,dp[i]);
            }
        }
        
        //  delete[] dp;
        return dp[n];
    }
    
private:

};
// @lc code=end


int main()
{
    Solution sol;
    cout << sol.numSquares(13) << endl;
    return 0;
}