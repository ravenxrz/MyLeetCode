#include "leetcode_base.h"

class Solution {
   public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // What if nums.size() == 1 ?
        int i = 0;
        int j = nums.size() - 1;
        while (i < j) {
            if (nums[i] + nums[j] == target) {
                return {nums[i], nums[j]};
            } else if (nums[i] + nums[j] < target) {
                i++;
            } else {
                j--;
            }
        }
        return {};  // If no such two numbers, what we should return?
    }
};

int main() {
    Solution sol;
    vector<int> nums = {2, 7, 11, 15};
    for (auto val : sol.twoSum(nums, 9)) {
        cout << val << ' ';
    }
    cout << endl;
    return 0;
}
