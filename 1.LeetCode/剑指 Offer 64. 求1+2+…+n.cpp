#include "leetcode_base.h"

class Solution {
   public:
    int sumNums(int n) {
        int x = n;
        bool flag = n > 0 && (x = n + sumNums(n - 1));
        return x;
    }
};

int main() {
	Solution sol;
	cout << sol.sumNums(10) << endl;
    return 0;
}