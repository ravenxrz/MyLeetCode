/**
 * @brief  01 背包问题， 表示有N件物品， 每件物品都有自己的value， weight， 给定一个weight上限为c的背包，
 * 问如何在不超过背包weight上限的前提下，拿到最大的value
 */

#include "leetcode_base.h"

int knapsack(const vector<int> &weight, const vector<int> &value, int c)
{
	assert(weight.size() == value.size());

	int dp[100][100]; // 这里暂定为100x100， 实际情况应该采用vector<vector>
	// init
	memset(dp, 0, sizeof(dp));
	// base state
	// In this case, we don't need to set the base state

	// Dp core algorithm
	for (int i = 1; i <= weight.size(); i++)
	{
		for (int j = 1; j <= c; j++)
		{
			if (j >= weight[i - 1])
			{ // 装得下
				dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i - 1]] + value[i - 1]);
			}
			else
			{
				// 装不下
				dp[i][j] = dp[i - 1][j];
			}
		}
	}

	return dp[weight.size()][c];
}

int main()
{
	//
	vector<int> weight = {1, 2, 3, 4};
	vector<int> value = {4, 3, 2, 4};
	int c = 9;
	cout << knapsack(weight, value, c) << endl;

	return 0;
}