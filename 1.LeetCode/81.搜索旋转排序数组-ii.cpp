/*
 * @lc app=leetcode.cn id=81 lang=cpp
 *
 * [81] 搜索旋转排序数组 II
 */
#include <bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        if(nums.empty())
            return false;
         if (nums.size() == 1) {
            return  nums[0] == target ;
        }
        // 找到反转点
        int point = 1;
        for (; point < nums.size(); point++) {
            if (nums[point - 1] > nums[point]) {
                // 找到反转点
                break;
            }
        }
        /* binary search */
        vector<int>::iterator iter;
        if (target >= nums[0]) {
            /* search in [0,point) */
            iter = std::lower_bound(nums.begin(), nums.begin() + point, target);
        } else {
            /* search in [point,end) */
            iter = std::lower_bound(nums.begin() + point, nums.end(), target);
        }
        if (iter != nums.end() && *iter == target) {
            return true;
        } else {
            return false;
        }
    }
};
// @lc code=end

