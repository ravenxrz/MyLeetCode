/*
 * @lc app=leetcode.cn id=7 lang=cpp
 *
 * [7] 整数反转
 */
#include <ctype>
// @lc code=start
class Solution {
public:
    int reverse(int x)
    {
     /*    int ret = 0;
        int tmp = 0;
        while (x) {
            // 越界判定条件
            tmp = (unsigned)ret * 10;  
            if(tmp/10 != ret)
                return 0;

            ret = ret * 10 + x % 10;
            x = x / 10;
        }
        return ret; */

     long ret = 0;
     while(x){
         ret = ret * 10 + x % 10;
         x = x / 10;
     }
     return ret > INT_MAX || ret < -INT_MAX -1? 0 : ret;
    }
};
// @lc code=end

