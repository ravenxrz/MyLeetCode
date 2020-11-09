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
        int i2 = 1;		// uglies[i2] = uglies[1] = 2 ==> 代表当前走到了2x2
        int i3 = 0;		// ==> 1x3
        int i5 = 0;		// ==> 1x5
        int v2, v3, v5;
        int counter = 5;
        int min_val = 5;
        while(counter != n){
            v2 = uglies[i2 + 1] * 2;
            v3 = uglies[i3 + 1] * 3;
            v5 = uglies[i5 + 1] * 5;
            min_val = min({ v2, v3, v5 });
            uglies.push_back(min_val);
            if(min_val == v2){
                i2++;
            }
            if(min_val == v3){
                i3++;
            }
            if (min_val == v5){
                i5++;
            }
            counter++;
        }
        return min_val;
    }
};
// @lc code=end

