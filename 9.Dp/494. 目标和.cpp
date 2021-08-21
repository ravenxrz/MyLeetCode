#include "leetcode_base.h"

class Solution
{
	int dp[1001];

public:
	int findTargetSumWays(vector<int> &nums, int target)
	{
		int sum = accumulate(nums.begin(), nums.end(), 0);
		if ((sum + target) & 1)
			return 0;
		if (target > sum || target < -sum)
			return 0;
		int new_target = (sum + target) >> 1;
		// init
		memset(dp, 0, sizeof(dp));
		// base state
		dp[0] = 1;
		// dp core algorithm
		for (int i = 1; i <= nums.size(); i++)
		{
			for (int j = new_target; j >= nums[i - 1]; j--)
			{
				dp[j] = dp[j] + dp[j - nums[i - 1]];
			}
		}
		return dp[new_target];
	}
};

int main()
{
	Solution sol;
	{
		vector<int> nums = {1, 1, 1, 1, 1};
		cout << sol.findTargetSumWays(nums, 3) << endl;
	}
	{
		vector<int> nums = {1};
		cout << sol.findTargetSumWays(nums, 1) << endl;
	}
	{
		vector<int> nums = {0, 0, 0, 0, 0, 1};
		cout << sol.findTargetSumWays(nums, 1) << endl;
	}

	return 0;
}