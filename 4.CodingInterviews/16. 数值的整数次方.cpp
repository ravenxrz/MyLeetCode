/**
 * 数值的整数次方
 * 题目：实现函数 double Power（double base， Int exponent），求base的exponent次方。不得使用库函数，同时不需要考虑大数问题。
 */
#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;


class Solution {
public:
    double myPow(double x, int n)
    {
        if (x == 0.0f || x == 1.0f) return x;
        
        long e = n;
        if (e < 0) {
            e = -e;
            x = 1 / x;
        }
        // 快速幂
        double res = 1;
        while(e){
            if( (e & 1) == 1){
                res *= x;
            }
            x *= x;
            e >>= 1;
        }
        return res;
    }
};

int main()
{
    Solution sol;
    {
        // x = 1
        cout << sol.myPow(1, 2) << endl;
        
        // x == 0
        cout << sol.myPow(0, 1) << endl;
        
        cout << sol.myPow(0, -1) << endl;
        
        // x < 0
        cout << sol.myPow(-1, 2) << endl;
        
        // n = 0
        cout << sol.myPow(2, 0) << endl;
        
        // n > 0
        cout << sol.myPow(2, 2) << endl;
        
        // n < 0
        cout << sol.myPow(2, -2) << endl;
        
        cout << sol.myPow(2, 32) << endl;
        
        cout << sol.myPow(-2, 2) << endl;
        
        cout << sol.myPow(0.00001, 0x7fffffff) << endl;
        
        cout << sol.myPow(1.00000, 0x80000000) << endl;
    }
    return 0;
}
