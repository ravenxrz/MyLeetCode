#include <iostream>
using namespace std;

class Solution {
   public:
    int mySqrt(int x) {
        int l = 0;
        int r = x;
        int mid = (l + r) >> 1;
        while (mid) {
            mid = (l + r) >> 1;
            if (mid > x / mid) {
                r = mid;
            } else if (mid == x / mid) {
                return mid;
            } else { /* mid * mid < x */
                if ((mid + 1) > x / (mid + 1))
                    return mid;
                l = mid + 1;
            }
        }
		return x == 1 ? 1 : 0;
    }
};

int main() {
    Solution sol;
    for (int i = 0; i < 100; i++) {
        cout << i << ":" << sol.mySqrt(i) << endl;
    }
    return 0;
}