/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
 * 
 * 方法一，回溯递归
 * 通过74/75，时间超时
 */
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    bool canJump(vector<int>& nums) {
        return solve(nums, 0);
    }

    /**
     * @brief 题解函数
     * 
     * @param nums 题目给定的数组
     * @param idx  当前所在位置
     * @return true 
     * @return false 
     */
    bool solve(const vector<int>& nums, int idx){
        if(idx == nums.size()-1)
            return true;
        
        if(idx >= nums.size())
            return false;

        for (int i = nums[idx]; i >= 1;i--){
            if(solve(nums,idx+i)){  
                return true;
            }
        }
        return false;
    }
};
// @lc code=end

