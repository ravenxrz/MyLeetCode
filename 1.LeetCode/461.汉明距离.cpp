/*
 * @lc app=leetcode.cn id=461 lang=cpp
 *
 * [461] 汉明距离
 */

// @lc code=start
class Solution {
public:
    int hammingDistance(int x, int y) {
        int sum = 0;
        int ret = x ^ y;
        while(ret != 0){
            if(ret & 0x1){
                sum++;
            }
            ret = ret >> 1;
        }
        return sum;
        }
};
// @lc code=end

