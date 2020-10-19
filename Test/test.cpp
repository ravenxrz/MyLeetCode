/*
 * @lc app=leetcode.cn id=7 lang=cpp
 *
 * [7] 整数反转
 */

// @lc code=start
class Solution {
public:
    int reverse(int x)
    {
        int ret = 0;
        int tmp = 0;
        while (x) {
            // 越界判定条件
            tmp = (unsigned)ret * 10;  
            if(tmp/10 != ret)
                return 0;

            ret = ret * 10 + x % 10;
            x = x / 10;
        }
        return ret;
    }
};
// @lc code=end

int main()
{
    int a = -1534236469;
    Solution sol;
    sol.reverse(a);
    return a;
}