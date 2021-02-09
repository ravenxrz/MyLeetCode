#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int> &nums)
    {
        if (nums.empty()) return 0;
        vector<int> dp(nums.size(), 0);
        // push first elem
        dp[0] = nums[0];
        int max_value = dp[0];
        for (int i = 1; i < nums.size(); i++) {
            dp[i] = max({nums[i], dp[i - 1] + nums[i]});
            max_value = max(dp[i],max_value);
        }
        return max_value;
    }
};

int main()
{
    Solution sol;
    {
        vector<int> nums{-1};
        cout << sol.maxSubArray(nums) << '\n';
    }
    return 0;
}
