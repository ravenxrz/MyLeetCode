#include "leetcode_base.h"

class Solution {
   public:
    int maxProduct(vector<int>& nums) {
        const int len = nums.size();

        int dp[len][2];
        dp[0][0] = nums[0];  // store max value
        dp[0][1] = nums[0];  // store min value
        for (int i = 1; i < len; i++) {
            dp[i][0] =
                max({nums[i], nums[i] * dp[i - 1][0], nums[i] * dp[i - 1][1]});
            dp[i][1] =
                min({nums[i], nums[i] * dp[i - 1][1], nums[i] * dp[i - 1][0]});
        }

        int max_value = INT32_MIN;
        for (int i = 0; i < len; i++) {
            max_value = max(max_value, dp[i][0]);
        }
        return max_value;
    }
};

int main() {
    Solution sol;
    {
        vector<int> nums = {2, 3, -2, 4};
        cout << sol.maxProduct(nums) << endl;
    }

    {
        vector<int> nums = {-2, 0, -1};
        cout << sol.maxProduct(nums) << endl;
    }

    {
        vector<int> nums = {-2, 3, -4};
        cout << sol.maxProduct(nums) << endl;
    }

    return 0;
}