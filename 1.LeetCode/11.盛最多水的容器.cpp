/*
 * @lc app=leetcode.cn id=11 lang=cpp
 *
 * [11] 盛最多水的容器
 */

#include <vector>
#include <iostream>
using namespace std;

// @lc code=start
class Solution {
public:
    int maxArea(vector<int>& height) {
        int global_max = 0;
        int loop_max = 0;
        int cur_height =1, pre_height = -1;

        for (int i = 1; i < height.size();i++){
            pre_height = height.at(i);
            for (int j = i - 1; j >= 0;j--){
                cur_height = height.at(j);
                if(cur_height >= pre_height){
                    // 尽量往左走
                    while(j-1 >= 0 && height[j-1]>= cur_height){
                        j--;
                    }
                }
                int capacity = (i - j) * min(cur_height,pre_height);
                if(loop_max < capacity){
                    loop_max = capacity;
                }
            }
            if(global_max < loop_max){
                global_max = loop_max;
            }
        }
        return global_max;
    }
};
// @lc code=end

int main()
{
    Solution sol;
    vector<int> height{ 1, 8, 6, 2, 5, 4, 8, 3, 7 };
    cout << sol.maxArea(height) << endl;
    return 0;
}