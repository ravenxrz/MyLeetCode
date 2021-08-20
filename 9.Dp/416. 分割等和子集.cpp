#include "leetcode_base.h"

class Solution
{
	bool dp[10001];

public:
	bool canPartition(vector<int> &nums)
	{
		int sum = accumulate(nums.begin(), nums.end(), 0);
		if (sum & 1)
		{
			return false;
		}

		int target = sum >> 1;
		// init
		memset(dp, 0, sizeof(dp));
		// base state
		dp[0] = true;

		//
		for (int i = 1; i <= nums.size(); i++)
		{
			for (int j = target; j >= 0; j--)
			{
				if (j >= nums[i - 1])
				{
					dp[j] = dp[j] | dp[j - nums[i - 1]];
				}
			}
		}
		return dp[target];
	}
};

int main()
{
	Solution sol;
	{
		vector<int> nums = {1, 5, 11, 5};
		cout << sol.canPartition(nums) << endl;
	}
	{
		vector<int> nums = {1, 2, 3, 5};
		cout << sol.canPartition(nums) << endl;
	}
	return 0;
}