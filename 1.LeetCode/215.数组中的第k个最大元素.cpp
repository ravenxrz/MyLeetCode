/*
 * @lc app=leetcode.cn id=215 lang=cpp
 *
 * [215] 数组中的第K个最大元素
 */
#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution {
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        return _find(nums, 0, nums.size() - 1, k-1);
    }


private:
    
    int _find(vector<int> &nums, int start, int end, int k)
    {
        int p = partition(nums, start, end);
        if (p < k) {
            return _find(nums, p + 1, end, k);
        } else if (p > k) {
            return _find(nums, start, p - 1, k);
        }
        return nums[p];
    }
    
    int partition(vector<int> &nums, int start, int end)
    {
        int pivot = nums[start];
        int i = start, j = end;
        while (i < j) {
            while (j > i && nums[j] <= pivot) j--;
            nums[i] = nums[j];
            while (i < j && nums[i] >= pivot) i++;
            nums[j] = nums[i];
        }
        nums[i] = pivot;
        return i;
    }
    
};
// @lc code=end

int main()
{
    Solution sol;
    vector<int> nums{3, 2, 3, 1, 2, 4, 5, 5, 6};
    cout << sol.findKthLargest(nums, 4) << endl;
    return 0;
}

