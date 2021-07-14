#include "leetcode_base.h"

class Solution {
   public:
    int rob(const vector<int>& nums) {
		if(nums.size() == 1) return nums[0];
        // contain first one and exclude last one
        int m1 = robmoney(vector<int>(nums.begin(), nums.end() - 1));
        int m2 = robmoney(vector<int>(nums.begin() + 1, nums.end()));
        return max(m1, m2);
    }

   private:
    int robmoney(const vector<int>& nums) {
        if (nums.empty())
            return 0;
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
    cout << sol.rob({2, 3, 2}) << endl;
    cout << sol.rob({1, 2, 3, 1}) << endl;
    cout << sol.rob({0}) << endl;
    return 0;
}