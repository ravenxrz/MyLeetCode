#include "leetcode_base.h"

class Solution {
   public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if (nums.empty())
            return {};
        assert(k <= nums.size() && k >= 1);

        vector<int> ans;
        int max_value = INT_MIN;
        int start = 0;
        int end = start + k - 1;
        // Init state
        max_value = *max_element(nums.begin(), nums.begin() + k);
        ans.push_back(max_value);
        start++;
        end++;

        while (end < nums.size()) {
            if (nums[end] >= max_value) {
                max_value = nums[end];
                ans.push_back(max_value);
            } else {
                if (nums[start - 1] == max_value) {
                    max_value = *max_element(nums.begin() + start,
                                             nums.begin() + end + 1);
                }
                ans.push_back(max_value);
            }
            start++;
            end++;
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 3, 01, 03, 5, 3, 6, 7};
    for (auto val : sol.maxSlidingWindow(nums, 3)) {
        cout << val << ' ';
    }
    return 0;
}