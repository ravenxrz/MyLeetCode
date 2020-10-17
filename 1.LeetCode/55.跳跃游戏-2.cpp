/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
 * 
 * 方法二，贪心算法
 * 
 */
#include <vector>
#include <iostream>
using namespace std;

// @lc code=start
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int max_jump = nums[0];
        int idx = 0;
        
        while(idx < nums.size() && idx <= max_jump){
            if(max_jump < nums[idx] + idx){
                max_jump = nums[idx] + idx;
            }
            idx++;
        }

        return max_jump >= nums.size()-1;
    }
};
// @lc code=end

int main()
{
    vector<int> vec{2, 3, 1, 1, 4};
    Solution sol;
    cout <<sol.canJump(vec);
    return 0;
}