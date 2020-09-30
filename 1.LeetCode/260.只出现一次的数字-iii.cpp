/*
 * @lc app=leetcode.cn id=260 lang=cpp
 *
 * [260] 只出现一次的数字 III
 */

// @lc code=start
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int temp = 0;
        for(const auto &val : nums){
            temp ^= val;
        }

        /* 最低位为1的点 */
        int offset = 0;
        const int int_bits = sizeof(int) * 8;
        for (int i = 0; i < int_bits;i++){
            int mask = 1 << i;
            if((temp & mask) != 0){
                offset = i;
                break;
            }
        }

        int num1 = 0, num2 = 0;
        /*  以offset为分界，讲nums分为两堆数组, 如果nums中的数字的offset位为1，则与num1异或，
            如果nums中的数字的offset位为0，则与num2异或
         */
        const int mask = 1 << offset;
        for(const auto &val : nums){
            if((val & mask) != 0){
                num1 ^= val;
            }else{
                num2 ^= val;
            }
        }
        
        /* 保存结果 */
        return vector<int> { num1, num2 };
    }
};
// @lc code=end

