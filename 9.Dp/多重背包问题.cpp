#include "leetcode_base.h"

int knapsack(const vector<int> &weight, const vector<int> &value, const vector<int> &nums, int c)
{
	assert(weight.size() == value.size() && weight.size() == nums.size());
	int dp[100][100]; // dp[i][j][k] 代表取前i个物品， 容量j是 最大价值

	// init
	memset(dp, 0, sizeof(dp));
	// base state
	for (int i = 1; i <= weight.size(); i++)
	{
		for (int j = 1; j <= c; j++)
		{
			for (int k = 0; k <= nums[i - 1]; k++)
			{
				if (k * weight[i - 1] <= j)
				{
					dp[i][j] = std::max(dp[i][j], dp[i - 1][j - k * weight[i - 1]] + k * value[i - 1]);
				}
				else
				{
					dp[i][j] = max(dp[i][j], dp[i - 1][j]);
				}
			}
		}
	}

	return dp[weight.size()][c];
}

int main()
{
	vector<int> weight = {1, 2, 3, 4};
	vector<int> value = {3, 2, 1, 4};
	vector<int> nums = {2, 3, 4, 2};
	int c = 9;
	cout << knapsack(weight, value, nums, c) << endl;
	return 0;
}