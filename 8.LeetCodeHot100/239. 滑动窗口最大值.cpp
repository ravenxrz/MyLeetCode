#include "leetcode_base.h"

/**
 * @brief 双端队列做法
 * 采用双端队列, 保证单调递减队列
 * 
 */
class Solution
{
public:
	vector<int> maxSlidingWindow(vector<int> &nums, int k)
	{
		deque<int> dq;
		vector<int> ans;
		ans.reserve(nums.size() - k + 1);

		// init state
		for (int i = 0; i < k; i++)
		{
			while (!dq.empty() && nums[i] > dq.back())
			{
				dq.pop_back();
			}
			dq.push_back(nums[i]);
		}
		ans.push_back(dq.front());

		// calc
		int left = 0;
		int right = k - 1;
		while (right != nums.size() - 1)
		{
			left++;
			right++;
			// First, check we need to pop from dq or not
			if (nums[left - 1] == dq.front())
			{
				dq.pop_front();
			}
			// Then, push the right value
			while (!dq.empty() && nums[right] > dq.back())
			{
				dq.pop_back();
			}
			dq.push_back(nums[right]);
			ans.push_back(dq.front());
		}

		return ans;
	}
};

/*
	优化后的O(nk)复杂度， 在超长的测试用例中，还是会超时
 */
// class Solution
// {
// public:
// 	vector<int> maxSlidingWindow(vector<int> &nums, int k)
// 	{
// 		vector<int> ans;
// 		ans.reserve(nums.size() - k + 1);

// 		// init state
// 		int left = 0;
// 		int right = k - 1;
// 		int max = *max_element(nums.begin() + left, nums.begin() + right + 1);
// 		ans.push_back(max);

// 		// Start to calc
// 		while (right != nums.size() - 1)
// 		{
// 			right++;
// 			left++;
// 			if (nums[left - 1] == max)
// 			{
// 				// Re calc the max value between [left, right]
// 				max = *max_element(nums.begin() + left, nums.begin() + right + 1);
// 			}
// 			else
// 			{
// 				if (nums[right] > max)
// 				{
// 					max = nums[right];
// 				}
// 			}
// 			ans.push_back(max);
// 		}
// 		return ans;
// 	}
// };

int main()
{
	Solution sol;
	vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
	int k = 3;
	for (auto val : sol.maxSlidingWindow(nums, k))
	{
		cout << val << endl;
	}
	return 0;
}