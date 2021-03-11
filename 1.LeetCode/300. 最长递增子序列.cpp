#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;


class Solution {
public:
    int lengthOfLIS(vector<int> &nums)
    {
        if (nums.empty()) return 0;
        // dp[i] 代表以nums[i] 为结尾的最长递增序列
        // 则dp[i] = max(dp[j] + 1).   nums[i] > nums[j] j \in [0,i-1]
        vector<int> dp(nums.size(), 1);
        int max_len = 1;
        for (int i = 1; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                    max_len = max(max_len, dp[i]);
                }
            }
        }
        return max_len;
    }
};

int main()
{
    Solution sol;
    {
        vector<int> nums{10, 9, 2, 5, 3, 7, 101, 18};
        cout << sol.lengthOfLIS(nums) << '\n';
    }
    return 0;
}
