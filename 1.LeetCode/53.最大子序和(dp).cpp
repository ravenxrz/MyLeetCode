#include "leetcode_base.h"

class Solution {
   public:
    int maxSubArray(const vector<int>& nums) {
        if (nums.empty())
            return 0;
        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            dp[i] = max(dp[i - 1] + nums[i], nums[i]);
        }
        // Find the maximum value in dp
        return *max_element(dp.begin(), dp.end());
    }
};

int main() {
    Solution sol;
    {
        cout << sol.maxSubArray({-2, 1, -3, 4, -1, 2, 1, -5, 4}) << endl;
        cout << sol.maxSubArray({1}) << endl;
        cout << sol.maxSubArray({5, 4, -1, 8}) << endl;
        cout << sol.maxSubArray({-2, 1, -3, 4, -1, 2, 1, -5, 4}) << endl;
        cout << sol.maxSubArray({}) << endl;
        cout << sol.maxSubArray({-1}) << endl;
    }
    return 0;
}