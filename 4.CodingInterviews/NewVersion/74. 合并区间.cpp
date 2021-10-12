#include "leetcode_base.h"

class Solution {
	bool Overlap(const vector<int> &int1, const vector<int>& int2){
		return !(int1[1] < int2[0]) && !(int1[0] > int2[1]);
	}

   public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty())
            return {};
        sort(intervals.begin(), intervals.end(), [](const vector<int>& lhs, const vector<int>& rhs) { return lhs[0] < rhs[0]; });

        vector<vector<int>> ans;
        ans.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); i++) {
            auto& last_interval = ans.back();
            if (Overlap(last_interval, intervals[i])) {
                last_interval[1] = max(last_interval[1], intervals[i][1]);
            } else {
				ans.push_back(intervals[i]);
			}
        }

		return ans;
    }
};