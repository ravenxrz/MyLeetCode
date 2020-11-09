/*
 * @lc app=leetcode.cn id=263 lang=cpp
 *
 * [263] 丑数
 */
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:

    int gcd(int a, int b){
        if(b == 0)
            return a;
        return gcd(b, a % b);
    }

    bool isUgly(int num) {
        if(num <= 0)
            return false;
        vector<int> factor { 2, 3, 5 };
        int idx = 0;
        while(num != 1){
            int g = gcd(num, factor[idx]);
            if(g == 1){
                idx++;
                if(idx == factor.size()){
                    return false;
                }
            }else if(g == 2 || g == 3 || g == 5){
                num = num / g;
            }else{
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

