#include "leetcode_base.h"

class Solution {
    int dp[101][2] [1000];  // dp[k][s][i] 代表第k次交易，手持s张股票，第i天时的最大利润
							// 规定卖出时，交易次数+1
   public:
    int maxProfit(int k, vector<int>& prices) {
		if(prices.empty()) return 0;
		memset(dp, 0, sizeof(dp));
		// init
		for(int idx = 0; idx < k; idx++){
			dp[idx][0][0] = 0;
			dp[idx][1][0] = -prices[0];
		}
		int max_value = 0;
		for(int ki = 0; ki <= k; ki++){
			for(int i = 1; i < prices.size(); i++){
				dp[ki][0][i] = max(dp[ki][0][i-1], ki == 0 ? 0 : dp[ki-1][1][i-1] + prices[i]);
				dp[ki][1][i] = max(dp[ki][1][i-1], dp[ki][0][i-1] - prices[i]);
			}
			max_value = max(max_value, dp[ki][0][prices.size() - 1]);
		}
		return max_value;
	}
};

int main() {
	Solution sol;
	vector<int> prices = {3,2,6,5,0,3};
	cout << sol.maxProfit(2, prices) << endl;
    return 0;
}