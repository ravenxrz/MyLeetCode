/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */
#include <iostream>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        if(nums.empty())
            return 0;
        int i = 0, j = 0;
        while(j<nums.size()){
            if(nums.at(j) != val){
                nums[i++] = nums[j];
            }
            j++;
        }
        return i;
    }
};
// @lc code=end

