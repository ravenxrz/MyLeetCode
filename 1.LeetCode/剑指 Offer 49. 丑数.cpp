#include "leetcode_base.h"

class Solution {
   public:
    int nthUglyNumber(int n) {
        assert(n >= 1);
        vector<int> ugly = {1, 2, 3, 4, 5};
        if (n <= 5)
            return ugly[n - 1];
        int i2 = 2;
        int i3 = 1;
        int i5 = 1;
        int target_num = 0;
        for (int i = 6; i <= n; i++) {
            target_num = min({ugly[i2] * 2, ugly[i3] * 3, ugly[i5] * 5});
            ugly.push_back(target_num);
            if (ugly[i2] * 2 == target_num) {
                i2++;
            }
            if (ugly[i3] * 3 == target_num) {
                i3++;
            }
            if (ugly[i5] * 5 == target_num) {
                i5++;
            }
        }
        return target_num;
    }
};

int main() {
    Solution sol;
    cout << sol.nthUglyNumber(10) << endl;
    return 0;
}