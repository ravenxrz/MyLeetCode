#include "leetcode_base.h"

class Solution {
   public:
    int search(vector<int>& nums, int target) {
		// Normal search
        auto it = std::lower_bound(nums.begin(), nums.end(), target);
        if (it == nums.end())
            return 0;
        int cnt = 0;
        while (it != nums.end() && *it == target) {
            it++;
			cnt++;
        }
		return cnt;
    }
};

int main() {
    return 0;
}