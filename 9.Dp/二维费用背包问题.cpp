#include "leetcode_base.h"

int knapsack(const vector<int> &weight, const vector<int> &volume, const vector<int> &value, int c, int v)
{
	int dp[100][100];
	memset(dp, 0, sizeof(dp));

	for (int i = 1; i <= weight.size(); i++)
	{
		for (int j = c; j >= 1; j--)
		{
			for (int k = v; k >= 1; k--)
			{
				if (j >= weight[i - 1] && k >= volume[i - 1])
				{
					dp[j][k] = max(dp[j][k], dp[j - weight[i - 1]][k - volume[i - 1]] + value[i - 1]);
				}
			}
		}
	}

	return dp[c][v];
}

int main()
{
	vector<int> weight = {1, 2, 3, 4};
	vector<int> value = {2, 3, 4, 5};
	vector<int> volume = {1, 3, 2, 4};
	cout << knapsack(weight, volume, value, 10, 10) << endl;
	return 0;
}