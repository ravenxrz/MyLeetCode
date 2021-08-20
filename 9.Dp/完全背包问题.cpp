#include "leetcode_base.h"

int knapsack(const vector<int> &weight, const vector<int> &value, int c)
{
	assert(weight.size() == value.size());

	int dp[100][100]; // dp[i][j] 代表， 取到前i个物品， 容量为j时的最大利润
	// init
	memset(dp, 0, sizeof(dp));
	// base state?
	// We don't need to set the base state

	// Dp core algorithm
	for (int i = 1; i <= weight.size(); i++)
	{
		for (int j = 1; j <= c; j++)
		{
			if (j >= weight[i - 1])
			{
				// 放得下
				dp[i][j] = max(dp[i - 1][j], dp[i][j - weight[i - 1]] + value[i - 1]);
			}
			else
			{
				// 放不下
				dp[i][j] = dp[i - 1][j];
			}
		}
	}

	return dp[weight.size()][c];
}

int main()
{
	vector<int> weight = {1, 2, 3, 4};
	vector<int> value = {2, 3, 2, 4};
	int c = 9;
	cout << knapsack(weight, value, c) << endl;
	return 0;
}