/*
 * @lc app=leetcode.cn id=33 lang=cpp
 *
 * [33] 搜索旋转排序数组
 */
#include <bits/stdc++.h>

using namespace std;

// @lc code=start
class Solution {
public:
    int search(vector<int> &nums, int target)
    {
        if (nums.size() == 1) {
            return  nums[0] == target ? 0 : -1;
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
            return iter - nums.begin();
        } else {
            return -1;
        }
    }
};
// @lc code=end

