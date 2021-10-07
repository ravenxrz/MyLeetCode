#include "leetcode_base.h"

class Solution {
   public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        set<long> window;
        for (int i = 0; i < nums.size(); i++) {
            long val = static_cast<long>(nums[i]) - t;
			auto iter = window.lower_bound(val);
			if(iter != window.end() && *iter <= static_cast<long>(t) + nums[i]){
				return true;
			}
            window.insert(nums[i]);
            if (window.size() > k)
                window.erase(nums[i - k]);
        }
        return false;
    }
};

int main() {
    vector<int> nums = {1, 2, 3, 1};
    Solution sol;
    cout << sol.containsNearbyAlmostDuplicate(nums, 3, 0) << endl;
    return 0;
}