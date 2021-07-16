#include "leetcode_base.h"

class Solution {
public:
    int integerBreak(int n)
    {
        if (n == 2) return 1;
        if (n == 3) return 2;
        if (n == 4) return 4;
        
        int num = 1;
        while (n) {
            if (n == 4) {    // 4 should be split to 2 + 2, not 1 + 3 for 1*3 < 2*2;
                n = 0;
                num *= 4;
                break;
            }
            
            if (n > 3) {
                n -= 3;
                num *= 3;
            } else {
                num *= n;
                n = 0;
            }
        }
        
        return num;
    }
};


int main()
{
    Solution sol;
    cout << sol.integerBreak(2) << endl;
    cout << sol.integerBreak(10) << endl;
    return 0;
}
