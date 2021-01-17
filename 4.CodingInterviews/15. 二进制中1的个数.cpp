/**
     15. 二进制中1的个数
    请实现一个函数，输入一个整数（以二进制串形式），输出该数二进制表示中 1 的个数。
    例如，把 9表示成二进制是 1001，有 2 位是 1。因此，如果输入 9，则该函数输出 2。
 */
#include <cassert>
#include <iostream>
#include <cmath>

using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n)
    {
        uint8_t count = 0;
        while (n) {
            count++;
            n = (n - 1) & n;
        }
        return count;
    }
};

int main()
{
    Solution sol;
    
    {
        cout << sol.hammingWeight(9) << endl;
        cout << sol.hammingWeight(0xfffffffd) << endl;
    }
    
    
    return 0;
}
