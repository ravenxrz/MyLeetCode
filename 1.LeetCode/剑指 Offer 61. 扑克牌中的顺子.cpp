#include "leetcode_base.h"

class Solution {
   public:
    bool isStraight(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int zero_card = 0;
        for (zero_card = 0; zero_card < nums.size() && nums[zero_card] == 0;
             zero_card++)
            ;
        if (zero_card == nums.size()) {  // 全为鬼牌
            return true;
        }
        for (int start = zero_card + 2; start < nums.size(); start++) {
            if (nums[start] - nums[start - 1] != 1) {
                zero_card -= (nums[start] - nums[start - 1] - 1);
                if (zero_card < 0)
                    return false;
            }
        }
        return true;
    }
};

int main() {
    Solution sol;
    {
        vector<int> nums = {1, 2, 3, 4, 5};
        cout << sol.isStraight(nums) << endl;
    }

    {
        vector<int> nums = {1, 2, 3, 0, 10};
        cout << sol.isStraight(nums) << endl;
    }

    return 0;
}
