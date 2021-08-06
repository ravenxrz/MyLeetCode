#include "leetcode_base.h"

class Solution {
   public:
    int missingNumber(vector<int>& nums) {
        int x = 0;
        for (int i = 1; i < nums.size(); i++) {
            x ^= nums[i];
            x ^= i;
        }
        x ^= nums.size() - 1;
        return x;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {0, 1, 3};
    cout << sol.missingNumber(nums) << endl;
    return 0;
}