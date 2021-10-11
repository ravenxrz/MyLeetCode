#include "leetcode_base.h"

class Solution {
   public:
    int mySqrt(int x) {
        if (x == 0)
            return 0;
        int l = 1;
        int r = x;
        while (l < r) {
            int mid = l + ((r - l) >> 1);
            if (mid > x / mid)
                r = mid;
            else if (mid == x / mid)
                return mid;
            else { /* mid < x / mid */
                if ((mid + 1) > x / (mid + 1)) {
                    return mid;
                }
                l = mid + 1;
            }
        }
        return l;
    }
};

int main() {
    Solution sol;
    cout << sol.mySqrt(10) << endl;
    return 0;
}