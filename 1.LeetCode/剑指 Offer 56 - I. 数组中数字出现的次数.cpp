#include "leetcode_base.h"

class Solution {
   public:
    vector<int> singleNumbers(vector<int>& nums) {
        int num = 0;
        for (int val : nums) {
            num ^= val;
        }

        // Get the offset of 1 in num  which counts form right
        int offset = 0;
        for (offset = 0; offset < 32; offset++) {
            if ((num >> offset) & 1) {
                break;
            }
        }

        // Reverse xor to get those two numbers
        int num1 = 0;
        int num2 = 0;
        for (int val : nums) {
            if ((val >> offset) & 1) {
                num1 ^= val;
            } else {
                num2 ^= val;
            }
        }
        return {num1, num2};
    }
};