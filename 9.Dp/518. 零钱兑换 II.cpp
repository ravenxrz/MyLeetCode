#include "leetcode_base.h"

class Solution
{
	int dp[5001];

public:
	int change(int amount, vector<int> &coins)
	{
		memset(dp, 0, sizeof(dp));
		int m = coins.size();
		// base state
		dp[0] = 1;
		//
		for (int i = 1; i <= m; i++)
		{
			for (int j = 1; j <= amount; j++)
			{
				if (j >= coins[i - 1])
				{
					dp[j] = dp[j] + dp[j - coins[i - 1]];
				}
			}
		}
		return dp[amount];
	}
};

int main()
{
	Solution sol;
	{
		vector<int> coins = {1, 2, 5};
		cout << sol.change(5, coins) << endl;
	}
	{
		vector<int> coins = {2};
		cout << sol.change(3, coins) << endl;
	}
	{
		vector<int> coins = {10};
		cout << sol.change(10, coins) << endl;
	}
	return 0;
}