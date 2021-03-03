#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    int duplicatedNumber(const vector<int>& nums) {
        if (nums.empty())
            return -1;
        return divide_find(nums, 1, nums.size());
    }

   private:
    int divide_find(const vector<int>& nums, int start, int end) {
        if (start < 0 || end > nums.size() || start > end)
            return -1;
        if (start == end)
            return nums[start - 1];
        int mid = (start + end) >> 1;
        // 统计在 [start, mid]和[mid+1,end]之间的数字
        int cnt1 = 0;
        int cnt2 = 0;
        for (int num : nums) {
            if (start <= num && num <= mid) {
                cnt1++;
            } else if (mid + 1 <= num && num <= end) {
                cnt2++;
            }
        }
        // 检查
        if (cnt1 > (mid - start + 1)) {
            return divide_find(nums, start, mid);
        } else if (cnt2 > (end - mid)) {
            return divide_find(nums, mid + 1, end);
        }
        // 实际上，不会走到这里，但是不写编译会警告
        return -1;
    }
};

int main() {
    Solution sol;
    // empty
    vector<int> nums1{};
    cout << sol.duplicatedNumber(nums1) << endl;

    // 输入数字不在[1,n] 范围内
    vector<int> nums2{1, 2, 3, 4, 5};  // n=4 输入范围应该为[1,4]
    cout << sol.duplicatedNumber(nums2) << '\n';

    // 有1个重复数字
    vector<int> num3{1, 2, 1, 3, 4};
    cout << sol.duplicatedNumber(num3) << '\n';

    // 有多个重复数字
    vector<int> num4{2, 2, 1, 3};
    cout << sol.duplicatedNumber(num4) << '\n';

    return 0;
}