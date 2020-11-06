/*
 * @lc app=leetcode.cn id=60 lang=cpp
 *
 * [60] 第k个排列
 */
#include <algorithm>
#include <string>
using namespace std;

// @lc code=start
class Solution {
public:
    string getPermutation(int n, int k) {
        string str;
        for (int i = 1; i <= n;i++){
            str += ('0' + i);
        }

        int counter = 1;
        while(counter < k){
            counter++;
            next_permutation(str.begin(), str.end());
        }
        return str;
    }
};
// @lc code=end

