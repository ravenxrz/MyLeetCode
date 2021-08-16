#include "leetcode_base.h"

class Solution {
   public:
    int maxProduct(vector<int>& nums) {
        if (nums.empty())
            return 0;
        vector<vector<int>> dp(2, vector<int>(nums.size(), 0));
        // init
        dp[0][0] = 0;
        dp[1][0] = 0;
        int ans = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            dp[0][i] =
                max({nums[i], nums[i] * dp[0][i - 1], nums[i] * dp[1][i - 1]});
            dp[1][i] =
                min({nums[i], nums[i] * dp[0][i - 1], nums[i] * dp[1][i - 1]});
            ans = max(ans, dp[0][i]);
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3, -1};
    cout << sol.maxProduct(nums) << endl;
    return 0;
}