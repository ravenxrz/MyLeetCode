#include "leetcode_base.h"

class Solution {
   public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.empty()) {
            return median(nums2);
        } else if (nums2.empty()) {
            return median(nums1);
        }
        vector<int> nums3(nums1.size() + nums2.size(), 0);
        // Merge sort
        int i = 0;
        int j = 0;
        int idx = 0;
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] < nums2[j]) {
                nums3[idx++] = nums1[i++];
            } else {
                nums3[idx++] = nums2[j++];
            }
        }
        while (i < nums1.size()) {
            nums3[idx++] = nums1[i++];
        }
        while (j < nums2.size()) {
            nums3[idx++] = nums2[j++];
        }
        return median(nums3);
    }

   private:
    double median(const vector<int>& nums) {
        if (nums.empty())
            return 0;
        if (nums.size() & 1) {
            return nums.at(nums.size() / 2);
        } else {
            return (nums.at((nums.size() - 1) / 2) + nums.at(nums.size() / 2)) /
                   2.0f;
        }
    }
};

int main() {
    Solution sol;
    vector<int> nums1 = {1, 2, 3, 4};
    vector<int> nums2 = {2, 3, 4, 5};
    cout << sol.findMedianSortedArrays(nums1, nums2) << endl;
    return 0;
}