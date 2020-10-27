/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除排序数组中的重复项
 */

#include <iostream>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;
        int i = 0, j = 1;
        while(j < nums.size()){
            if(nums[j] != nums[j-1]){
                nums[++i] = nums[j];
            }
            j++;
        }
        return i + 1;
    }
};
// @lc code=end

int main(int argc, const char** argv) {
    Solution sol;
    vector<int> nums{1, 1, 2, 2, 3, 3, 3};
    int len = sol.removeDuplicates(nums);
    for (int i = 0; i < len;i++){
        cout << nums[i] << " ";
    }
    cout << endl;
    return 0;
}