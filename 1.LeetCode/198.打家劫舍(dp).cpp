#include "leetcode_base.h"

class Solution {
   public:
    int rob(const vector<int>& nums) {
        vector<int> dp(nums.size() + 1, 0);
        dp[1] = nums[0];
        for (int i = 2; i < dp.size(); i++) {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i - 1]);
        }
        return dp.back();
    }
};

int main() {
    Solution sol;
    cout << sol.rob({1, 2, 3, 1}) << endl;
    cout << sol.rob({2, 7, 9, 3, 1}) << endl;
    return 0;
}