#include "leetcode_base.h"

class Solution {
   public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> num2freq;
        map<int, vector<int>> freq2num;
        for (auto val : nums) {
            num2freq[val]++;
        }
        for (auto entry : num2freq) {
            if (!freq2num.count(entry.second)) {
                freq2num[entry.second] = {entry.first};
            } else {
                freq2num[entry.second].push_back(entry.first);
            }
        }
        assert(!freq2num.empty());

        vector<int> ans;
        int cnt = 0;

        for (auto iter = freq2num.rbegin(); iter != freq2num.rend() && cnt < k;
             iter++) {
            const vector<int>& values = iter->second;
            ans.insert(ans.end(), values.begin(), values.end());
            cnt += values.size();
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {4, 1, -1, 2, -1, 2, 3};
    int k = 2;
    for (auto val : sol.topKFrequent(nums, k)) {
        cout << val << ' ';
    }
    cout << endl;
    return 0;
}