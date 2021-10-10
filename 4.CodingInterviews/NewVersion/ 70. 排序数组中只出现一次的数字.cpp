#include "leetcode_base.h"

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
		int n = nums.front();
		for(int i = 1; i< nums.size(); i++){
			n ^= nums[i];
		}
		return n;
    }

};