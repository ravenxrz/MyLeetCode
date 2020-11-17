/*
 * @lc app=leetcode.cn id=477 lang=cpp
 *
 * [477] 汉明距离总和
 */
#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    /**
     * @brief 暴力解法
     *
     * @param num1
     * @param num2
     * @return int
     */
    int report(int num1, int num2) const
    {
        int counter = 0;
        static int mask;
        static const int len = sizeof(num1) * 8;
        mask = 0x1;
        int result = num1 ^ num2;
        for (int i = 1; i < len; i++) {
            if ((result & mask) != 0) {
                counter++;
            }
            mask = (mask << 1);
        }
        return counter;
    }

    int baoli(vector<int>& nums)
    {
        if (nums.empty())
            return 0;
        int ans = 0;
        for (int i = 0; i < nums.size() - 1; i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                ans += report(nums[i], nums[j]);
            }
        }
        return ans;
    }

    int totalHammingDistance(vector<int>& nums)
    {
        const int len = sizeof(int) * 8;
        int ans = 0;
        // 记录每个bit位有多少个1
        int* record = new int[len];
        memset(record, 0, len*sizeof(int));
        for(auto &num : nums){
            for (int i = 0; num != 0 && i < len-1;i++){
                if((num & 0x1) != 0){
                    record[i]++;
                }
                num = num >> 1;
            }
        }
        // 计算结果
        for (int i = 0; i < len;i++){
            ans += (record[i]) * (nums.size() - record[i]);
        }
        // delete[] record;
        return ans;
    }
};
// @lc code=end

int main()
{
    Solution sol;
    vector<int> nums{1,2,3};
    cout << sol.totalHammingDistance(nums);
    return 0;
}