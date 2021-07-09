#include "leetcode_base.h"

class Solution {
   public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> seqs;

        for (int val : nums) {
            if (seqs.empty() || seqs.back() < val) {
                seqs.push_back(val);
            } else {
                // use binary search to locate the value which is the first one
                // large or equals 'val'
                auto it = std::lower_bound(seqs.begin(), seqs.end(), val);
                assert(it != seqs.end());
                *it = val;
            }
        }
        return seqs.size();
    }
};

int main() {
    Solution sol;
    {
        vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
        cout << sol.lengthOfLIS(nums) << endl;
    }
    return 0;
}