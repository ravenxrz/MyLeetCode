/*
 * @lc app=leetcode.cn id=442 lang=cpp
 *
 * [442] 数组中重复的数据
 */

#include <iostream>
#include <vector>
#include <map>
using namespace std;

// @lc code=start
class Solution {
public:

    inline int abs(int a){
        return a>0? a: -a;
    }
    /**
     * 不能使用额外空间，则只能就地更新
     * 判定条件为2次，则可用相反数表征
     * 对于同一个数字，他们的范围是 1<=a[i]<=n. 可用他们作索引，
     * 第一个数字索引到该位置时，修改改位置元素为负数，第二个元素索引到该
     * 位置时，则加入。
     */
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;

        for(auto &val : nums){
            int abs_val = abs(val);
            if(nums[abs_val-1] <0 ){
                ans.push_back(abs_val);
            }else{
                nums[abs_val-1] = -nums[abs_val-1];
            }
        }

        return ans;
    }
};
// @lc code=end


int main()
{

    return 0;
}
