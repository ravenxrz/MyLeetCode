/**
 *   给你一根长度为 n 的绳子，请把绳子剪成整数长度的 m 段（m、n都是整数，n>1并且m>1），
 *   每段绳子的长度记为 k[0],k[1]...k[m-1] 。
 *   请问 k[0]*k[1]*...*k[m-1] 可能的最大乘积是多少？
 *   例如，当绳子的长度是8时，我们把它剪成长度分别为2、3、3的三段，此时得到的最大乘积是18。
 */
#include <cassert>
#include <iostream>
#include <cmath>

using namespace std;

class Solution {
public:
    int cuttingRope(int n)
    {
        if (n <= 1) return 0;
        else if (n == 2) return 1;
        else if (n == 3) return 2;
        else if (n == 4) return 4;
        // n>= 5
        int times_of_3 = n / 3;
        if (n - times_of_3 * 3 == 1) {     // 如果剩余1，说明最后一段等于4， 那么应该拆分成2x2，而不是1x3
            times_of_3--;
        }
        int times_of_2 = (n - times_of_3 * 3) / 2;
        return (int) pow(3, times_of_3) * (int) pow(2, times_of_2);
    }
};


int main()
{
    Solution sol;
    
    {
        cout << sol.cuttingRope(2) << endl;
        cout << sol.cuttingRope(3) << endl;
        cout << sol.cuttingRope(4) << endl;
        cout << sol.cuttingRope(8) << endl;
        cout << sol.cuttingRope(58) << endl;
    }
    
    
    return 0;
}
