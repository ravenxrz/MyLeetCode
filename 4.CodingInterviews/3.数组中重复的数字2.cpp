/**
 *
 *      题目：不修改数组找出重复的数字
        在一个长度为n+1的数组里的所有数字都在1~n的范围内，所以数组
        中至少有一个数字是重复的。请找出数组中任意一个重复的数字，但不能
        修改输入的数组。例如，如果输入长度为8的数组{2，3，5，4，3，2，6，7}，那
        么对应的输出是重复的数字2或者3
        要求： 空间复杂度为O(1), 且不能修改输入数组
 */
#include <vector>
#include <iostream>

using namespace std;

// 递归版本
class Solution1 {
public:
    int divide_find(const vector<int> &nums, int start, int end)
    {
        if (start > end) {
            return -1;
        }
        
        const int mid = (start + end) >> 1;
        int pre_cnt = 0;    // count nums in [start,mid]
        int suf_cnt = 0;    // count nums in (mid,end]
        for (int num : nums) {
            if (num <= mid && num >= start) {
                pre_cnt++;
            } else if (num > mid && num <= end) {
                suf_cnt++;
            }
        }
        
        if (pre_cnt > (mid - start + 1)) {
            if (start == mid) return start;
            return divide_find(nums, start, mid);
        } else if (suf_cnt > (end - mid)) {
            if (mid + 1 == end) return end;
            return divide_find(nums, mid + 1, end);
        }
        return -1;
    }
    
    int duplicatedNumber(const vector<int> &nums)
    {
        if (nums.empty()) return -1;
        
        // 验证 n+1个数字是否在[1,n]内
        const int n = nums.size() - 1;
        for (int i = 0; i <= n; i++) {
            if (nums[i] < 1 || nums[i] > n) {
                return -1;
            }
        }
        
        // 正式算法--减治法
        return divide_find(nums, 1, n);
    }
    
};


// 非递归版本
class Solution2 {
public:
    int duplicatedNumber(const vector<int> &nums)
    {
        if (nums.empty()) return -1;
        
        // 验证 n+1个数字是否在[1,n]内
        const int n = nums.size() - 1;
        for (int i = 0; i <= n; i++) {
            if (nums[i] < 1 || nums[i] > n) {
                return -1;
            }
        }
        
        // 正式算法
        int i = 1, j = n;
        while (i <= j) {
            int mid = (i + j) >> 1;
            int cnt = countNumberInRange(nums, i, mid);
            if (i == j) { // or move this condition to out of this loop
                if (cnt > (mid - i + 1)) return i;
                else return -1;
            }
            
            if (cnt > (mid - i + 1)) { // in range [i,mid]
                j = mid;
            } else {  // in range [mid+1,j]
                i = mid + 1;
            }
        }
        
        return -1;
    }
    
    int countNumberInRange(const vector<int> &nums, int start, int end)
    {
        int cnt = 0;
        for (auto num : nums) {
            if (start <= num && num <= end) {
                cnt++;
            }
        }
        return cnt;
    }
};

int main()
{
    Solution1 sol1;
    Solution2 sol2;
    // empty
    vector<int> nums1{};
    cout << sol1.duplicatedNumber(nums1) << '\n';
    cout << sol2.duplicatedNumber(nums1) << '\n';
    
    // 输入数字不在[1,n] 范围内
    vector<int> nums2{1, 2, 3, 4, 5};       // n=4 输入范围应该为[1,4]
    cout << sol1.duplicatedNumber(nums2) << '\n';
    cout << sol2.duplicatedNumber(nums2) << '\n';
    
    // 有1个重复数字
    vector<int> num3{1, 2, 1, 3, 4};
    cout << sol1.duplicatedNumber(num3) << '\n';
    cout << sol2.duplicatedNumber(num3) << '\n';
    
    // 有多个重复数字
    vector<int> num4{2, 2, 1, 3};;
    cout << sol1.duplicatedNumber(num4) << '\n';
    cout << sol2.duplicatedNumber(num4) << '\n';
    
    
    return 0;
}
