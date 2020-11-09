/*
 * @lc app=leetcode.cn id=264 lang=cpp
 *
 * [264] 丑数 II
 */
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

// @lc code=start
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> uglies { 1, 2, 3,4, 5 };
        if(n <= uglies.size())
            return uglies[n - 1];
        int i2 = 1;
        int i3 = 0;
        int i5 = 0;
        int v2, v3, v5;
        int counter = 5;
        int max = 5;
        while(counter != n){
            v2 = uglies[i2 + 1] * 2;
            v3 = uglies[i3 + 1] * 3;
            v5 = uglies[i5 + 1] * 5;
            max = min({ v2, v3, v5 });
            uglies.push_back(max);
            if(max == v2){
                i2++;
            }
            if(max == v3){
                i3++;
            }
            if (max == v5){
                i5++;
            }
            counter++;
        }
        return max;
    }
};
// @lc code=end

int main()
{
    Solution sol;
    cout << sol.nthUglyNumber(11);
    return 0;
}