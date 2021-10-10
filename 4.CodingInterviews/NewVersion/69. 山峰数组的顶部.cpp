#include "leetcode_base.h"

class Solution {
   public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int l = 0;
        int r = arr.size() - 1;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (mid - 1 >= 0 && mid + 1 < arr.size() &&
                arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1]) {
                return mid;
            }
            if (mid + 1 < arr.size()) {
                if (arr[mid] < arr[mid + 1]) {
                    l = mid + 1;
                } else if (arr[mid] > arr[mid + 1]) {
                    r = mid;
                }
            }
        }
        return l;
    }
};