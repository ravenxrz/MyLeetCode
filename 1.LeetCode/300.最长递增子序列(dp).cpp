#include "leetcode_base.h"

class Solution {
   public:
    int lengthOfLIS(vector<int>& nums) {
        assert(!nums.empty());
        // dp solver
        vector<int> dp(nums.size(), 1);
        int max_length = 1;
        for (int i = 1; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
				if(nums[i] > nums[j])
					dp[i] = max(dp[i], dp[j] + 1);
            }
            max_length = max(max_length, dp[i]);
        }
        return max_length;
    }
};

int main() {
    Solution sol;
    {
        vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
        cout << sol.lengthOfLIS(nums) << endl;
    }
    return 0;
}