/*
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

#include <iostream>
#include <map>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> hashmap;
        // 注入所有元素到hashmap中
        for (int i = 0; i < nums.size();i++){
            hashmap[nums[i]] = i;
        }

        // 求解
        int idx1 = -1, idx2 = -1;
        for (idx1 = 0; idx1 < nums.size() - 1;idx1++){
            if(hashmap.find(target - nums[idx1]) != hashmap.end()
                && hashmap[target - nums[idx1]] != idx1){
                idx2 = hashmap[target - nums[idx1]];
                break;
            }
        }
        return vector<int> { idx1, idx2 };
    }
};
// @lc code=end
