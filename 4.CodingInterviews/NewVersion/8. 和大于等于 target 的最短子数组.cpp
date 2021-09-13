#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int minSubArrayLen(int target, vector<int>& nums) {
        vector<int> sum_array(nums.size() + 1, 0);
        for (int i = 0; i < nums.size(); i++) {
            sum_array[i + 1] = (sum_array[i] + nums[i]);
        }

        // slide  window
        int l = 1;
        int r = 1;
        int min_len = INT_MAX;
        while (r < sum_array.size()) {
            int sum = sum_array[r] - sum_array[l - 1];
            while (sum >= target) {
                min_len = min(min_len, r - l + 1);
                cout << l << ' ' << r << ' ' << min_len << endl;
                // shrinks
                l++;
                sum = sum_array[r] - sum_array[l - 1];
            }
            r++;
        }
        return min_len == INT_MAX ? 0 : min_len;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {2, 3, 1, 2, 4, 3};
    cout << sol.minSubArrayLen(7, nums) << endl;
    return 0;
}