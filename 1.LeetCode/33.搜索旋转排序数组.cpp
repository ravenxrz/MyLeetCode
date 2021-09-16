/*
 * @lc app=leetcode.cn id=33 lang=cpp
 *
 * [33] 搜索旋转排序数组
 */
#include <bits/stdc++.h>

using namespace std;


class Solution {
   public:
    int search(vector<int>& nums, int target) {
        return searchCore(nums, 0, nums.size() - 1, target);
    }

   private:
    int searchCore(const vector<int>& nums, int left, int right, int target) {
        if (left > right)
            return -1;
        if (left == right)
            return nums[left] == target ? left : -1;
        int mid = (left + right) >> 1;
        if (nums[left] <= nums[mid]) {
            if (target >= nums[left] && target <= nums[mid])
                return searchCore(nums, left, mid, target);
            else
                return searchCore(nums, mid + 1, right, target);
        } else {
            if (nums[mid + 1] >= target && target <= nums[right])
                return searchCore(nums, mid + 1, right, target);
            else
                return searchCore(nums, left, mid, target);
        }
    }
};


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

class Solution {
   public:
    int search(vector<int>& nums, int target) {
        if (nums.size() == 1)
            return nums[0] == target ? 0 : -1;

        if (nums.front() <
            nums.back()) { /* 没有旋转，或者旋转了L*nums.size() 次 */
            auto iter = lower_bound(nums.begin(), nums.end(), target);
            if (iter != nums.end() && *iter == target)
                return iter - nums.begin();
            return -1;
        }

        /* 分成了两段式 */
        int l = 0;
        int r = nums.size() - 1;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (nums[mid] == target)
                return mid;

            if (target >= nums[0]) {        /* target is in the left section */
                if (nums[mid] >= nums[0]) { /* mid is in the left section */
                    if (nums[mid] > target)
                        r = mid - 1;
                    else
                        l = mid + 1;
                } else { /* mid is in the right section */
                    r = mid - 1;
                }
            } else {                        /* target is in the right section */
                if (nums[mid] >= nums[0]) { /* mid is in the left section */
                    l = mid + 1;
                } else { /* mid is in the right section  */
                    if (nums[mid] > target)
                        r = mid - 1;
                    else
                        l = mid + 1;
                }
            }
        }
        return nums[l] == target ? l : -1;
    }
};


