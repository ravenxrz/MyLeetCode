#include "leetcode_base.h"

class Solution {
   public:
    int singleNumber(vector<int>& nums) {
        int record[32];
        memset(record, 0, sizeof(record));
        for (auto val : nums) {
            for (int i = 0; i < 32; i++) {
                if ((val >> i) & 1) {
                    record[i]++;
                }
            }
        }

        // Check whether record[i] % 32 is 0 or not, if is 1 , cnt it
        int ans = 0;
        for (int i = 0; i < 32; i++) {
            if (record[i] % 3) {
                ans |= (1 << i);
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {3, 4, 3, 3};
    cout << sol.singleNumber(nums) << endl;
    return 0;
}