/*
 * @lc app=leetcode.cn id=80 lang=cpp
 *
 * [80] 删除排序数组中的重复项 II
 */

#include <vector>
#include <iostream>
using namespace std;


// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.empty()) return 0;
        int i = 1,j = 1;
        int counter = 1;
        while(j < nums.size()){
            while(j<nums.size() && nums[j] == nums[j-1]){
                if(counter < 2){
                    nums[i++] = nums[j];
                    counter++;
                }
                j++;
            }
            if(j >= nums.size()) break;
            nums[i++] = nums[j];
            counter = 1;
            j++;
        }
        return i;
    }
};
// @lc code=end

int main()
{
    Solution sol;
    vector<int> nums{0,0,1,1,1,1,2,3,3};
    int len =  sol.removeDuplicates(nums);
    for(int i = 0;i<len;i++){
        cout << nums[i] << " ";
    }
    return 0;
}