/*
 * @lc app=leetcode.cn id=189 lang=cpp
 *
 * [189] 旋转数组
 */
#include <bits/stdc++.h>
using namespace std;

// @lc code=start
class Solution {
public:
    // my rotate 1
    void my_rotate1(vector<int>& nums,int k){
        const int len = nums.size();
        k = k % len;
        nums.insert(nums.begin(),nums.end()-k,nums.end());
        nums.resize(len);
    }
    
    // 反转法
    void rotate(vector<int>& nums, int k){
        k = k % nums.size();
        reverse(nums.begin(),nums.end());
        reverse(nums.begin(),nums.begin()+k);
        reverse(nums.begin()+k,nums.end());
    }
};
// @lc code=end

int main()
{
    Solution sol;
    vector<int> vec{1,2,3};
    sol.rotate(vec,1);
    for(auto val : vec){
        cout << val << " ";
    }
    return 0;
}