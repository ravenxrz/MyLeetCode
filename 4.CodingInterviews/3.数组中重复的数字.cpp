/**
    题目：数组中重复的数字
    在一个长度为n的数组里的所有数字都在0~m-1的范围内。
    数组中某些数字是重复的，但不知道有几个数字重复了，也不知道每个数字重复了几次。
    请找出数组中任意一个重复的数字。
    例如，如果输入长度为7的数组{2，3，1，0，2，5，3}，那么对应的输出是重复的数字2或者3
 */
#include <vector>
#include <iostream>

using namespace std;

int duplicatedNumber(vector<int> nums)
{
    if (nums.empty()) {
        return -1;
    }
    
    const int len = nums.size();
    // 验证是否在 [0-n-1]这个范围内
    for (int i = 0; i < len; i++) {
        if (nums[i] < 0 || nums[i] >= len) {
            return -1;
        }
    }
    
    // find one duplicated number
    for (int i = 0; i < len; i++) {
        while (i != nums[i]) {
            if (nums[i] == nums[nums[i]]) {
                return nums[i];
            } else {
                // swap
                int t = nums[i];
                nums[i] = nums[t];
                nums[t] = t;
            }
        }
    }
    return -1;
}

int main()
{
    // empty
    vector<int> nums1;
    cout << duplicatedNumber(nums1) << endl;
    
    // 不包含重复数字
    vector<int> nums2{1, 2, 3, 4, 5, 0};
    cout << duplicatedNumber(nums2) << endl;
    
    // 包含一个重复数字
    vector<int> nums3{2, 3, 1, 0, 2, 5, 3};
    cout << duplicatedNumber(nums3) << endl;
    
    // 包含多个重复数字
    vector<int> nums4{2, 2, 2, 2, 2, 2, 2, 4};
    cout << duplicatedNumber(nums4) << endl;
    return 0;
}
