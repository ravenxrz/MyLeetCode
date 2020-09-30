/*
 * @lc app=leetcode.cn id=137 lang=cpp
 *
 * [137] 只出现一次的数字 II
 */

// @lc code=start
class Solution {
public:
    int singleNumber(vector<int>& nums)
    {
        const int int_bits = sizeof(int) * 8;
        short* counter = new short[int_bits];
        int result = 0;

        /* initialize */
        for (int i = 0; i < int_bits; i++) {
            counter[i] = 0;
        }

        for (int i = 0; i < nums.size(); i++) {
            int val = nums.at(i);
            for (int j = 0; j < int_bits; j++) {
                int mask = 1 << j;
                if ((val & mask) != 0) {
                    counter[j]++;
                }
            }
        }

        /* 计算最终结果 */
        for (int i = 0; i < int_bits; i++) {
            if (counter[i] % 3 == 1) {
                result |= (1 << i);
            }
        }

        delete[] counter;
        return result;
    }
};
// @lc code=end
