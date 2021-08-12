#include "leetcode_base.h"

class Solution {
   public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int left = 0;
        int right = nums.size() - 1;
        vector<vector<int>> ans;
		int prev_num = INT_MAX;

        for (int i = 0; i < nums.size();i++) {
			int c = nums[i];
			if(c == prev_num) continue; // 跳过已经算过的value
			prev_num = c;

            left = i + 1;
            right = nums.size() - 1;
            while (left < right) {
                if (nums[left] + nums[right] + c == 0) {
                    ans.push_back({c, nums[left], nums[right]});
                    // 跳过所有left相同value和right相同value
					left++;
                    while (left  < right && nums[left] == nums[left - 1]) {
                        left++;
                    }
					right--;
                    while (right  > left && nums[right] == nums[right + 1]) {
                        right--;
                    }
                } else if (nums[left] + nums[right] + c > 0) {
                    right--;
                } else {
                    left++;
                }
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {0};
    for (const auto& vec : sol.threeSum(nums)) {
        for (auto val : vec) {
            cout << val << ' ';
        }
        cout << endl;
    }
    return 0;
}