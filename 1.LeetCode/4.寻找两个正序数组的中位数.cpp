#include <vector>
#include <iostream>

using namespace std;


class Solution {
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
    {
        size_t size = nums1.size() + nums2.size();
        if (size & 1) {
            return findMedian(nums1, 0, nums2, 0, (size + 1) >> 1);
        } else {
            return static_cast<double>(
                           findMedian(nums1, 0, nums2, 0, (size >> 1)) +
                           findMedian(nums1, 0, nums2, 0, (size >> 1) + 1)
                   ) / 2;
        }
    }

public:
    // k start from 1
    double findMedian(vector<int> &nums1, int s1, vector<int> &nums2, int s2, size_t k)
    {
        if (s1 >= nums1.size() && s2 >= nums2.size()) return 0;
        if (s1 >= nums1.size()) { // s2 < nums2.size()
            return nums2[s2 + k - 1];
        }
        if (s2 >= nums2.size()) { // s1 < nums1.size()
            return nums1[s1 + k - 1];
        }
        if (k == 1) {
            return min(nums1[s1], nums2[s2]);
        }
        // s1 < nums1.size() && s2 < nums2.size()
        int n1_idx = min(s1 + k / 2 - 1, nums1.size() - 1);
        int n2_idx = min(s2 + k / 2 - 1, nums2.size() - 1);
        if (nums1[n1_idx] <= nums2[n2_idx]) {
            return findMedian(nums1, n1_idx + 1, nums2, s2, k - (n1_idx - s1 + 1));
        } else {
            return findMedian(nums1, s1, nums2, n2_idx + 1, k - (n2_idx - s2 + 1));
        }
    }
};

