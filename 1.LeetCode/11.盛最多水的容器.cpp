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


    int baoli(vector<int>& height){
         int global_max = 0;
        int loop_max = 0;
        int cur_height =1, pre_height = -1;

        int loop_pair_loc = 0;     // 记录形成最大容量时的第一个柱子
        int global_pair_loc = 0;

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
                    loop_pair_loc = j;
                }
            }
            if(global_max < loop_max){
                global_max = loop_max;
                global_pair_loc = loop_pair_loc;
            }
            // 尽可能跳过持续下降的柱子
            int i_save = i;
            while(i+1 < height.size()-1 && height[i+1] < height[i]){
                i++;
                if((i - i_save) * height[i] > global_max){
                    global_max = (i - i_save) * height[i];
                    break;
                }
                if((i - global_pair_loc) * min(height[i],height[global_pair_loc]) > global_max){
                    global_max = (i - global_pair_loc) * min(height[i],height[global_pair_loc]);
                    break;
                }
            }
        }
        return global_max;
    }

    int maxArea(vector<int>& height) {
        int l = 0;
        int r = height.size() - 1;
        int max = 0;
        while (l < r)
        {
            int area = (r - l ) * min(height[l], height[r]);
            if (max <area)
                max = area;
            if(height[l] > height[r]){
                r--;
            }else{
                l++;
            }
        }
        return max;
    }
};
// @lc code=end

int main()
{
    Solution sol;
    vector<int> height{ 1,8,6,2,5,4,8,3,7};
    cout << sol.maxArea(height) << endl;
    return 0;
}