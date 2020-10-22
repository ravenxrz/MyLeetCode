/*
 * @lc app=leetcode.cn id=744 lang=cpp
 *
 * [744] 寻找比目标字母大的最小字母
 */

#include <vector>
#include <algorithm>
using namespace std;

// @lc code=start
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        vector<int> nums;
        transform(letters.begin(), letters.end(), nums.begin(),
            [&](const char& x) {
                return x - 'a';
            });
        int target_num = target - 'a';

        // 二分查找
        int i = 0, j = nums.size() - 1;
        int mid = (i+j)/2;
        while(i<j){
            if(nums.at(mid) < target_num){
                i = mid + 1;
            }else if(nums.at(mid) > target_num){
                j = mid - 1;
            }else{  // 找到相等的
                return nums[(i + 1) % 26] + 'a';
            }
            mid = (i + j) / 2;
        }
        //  i>=j， 说明没有目标值
        if(nums.at(mid) > target_num){
            return mid;
        }else {
            return nums[(i + 1) % 26] + 'a';
        }
    }
};
// @lc code=end

