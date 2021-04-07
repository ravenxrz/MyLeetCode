#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int> &nums)
    {
        if (nums.empty()) return 0;
        vector<int> top;
        top.push_back(nums[0]);
        
        for (int i = 1; i < nums.size(); i++) {
            if (top.back() < nums[i]) {
                top.push_back(nums[i]);
            } else {
                int idx = find_first_less_than(top, nums[i]);
                top[idx + 1] = nums[i];
            }
        }
        return top.size();
    }

private:
    int find_first_less_than(vector<int> &nums, int target)
    {
        int l = 0;
        int r = nums.size() - 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] == target) {
                r = mid - 1;
            } else if (nums[mid] < target) {
                l = mid + 1;
            } else if (nums[mid] > target) {
                r = mid - 1;
            }
        }
        return r;
    }
};


/**
 * 找到第一个比target小的数字，找不到返回-1
 * @param nums
 * @param target
 * @return
 */
int binary_search_first_less_than(const vector<int> &nums, int target)
{
    int l = 0;
    int r = nums.size() - 1;
    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (nums[mid] == target) {
            r = mid - 1;
        } else if (nums[mid] < target) {
            l = mid + 1;
        } else if (nums[mid] > target) {
            r = mid - 1;
        }
    }
    if (l == nums.size()) return -1;
    return r >= 0 ? nums[r] : -1;
}

int main()
{
    vector<int> nums{1, 4, 6, 7, 8, 10};
    cout << binary_search_first_less_than(nums, 2) << '\n';
    cout << binary_search_first_less_than(nums, 5) << '\n';
    cout << binary_search_first_less_than(nums, 8) << '\n';
    cout << binary_search_first_less_than(nums, 9) << '\n';
    cout << binary_search_first_less_than(nums, 1) << '\n';
    return 0;
}

