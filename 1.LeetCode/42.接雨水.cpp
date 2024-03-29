//
// Created by Raven on 2021/2/26.
//
#include <stack>
#include <vector>
#include <iostream>

using namespace std;


class Solution {
   public:
    int trap(vector<int>& height) {
        int ans = 0;
        int left_max = 0;
        int right_max = 0;
        int left = 0;
        int right = height.size() - 1;

        while (left <= right) {
            if (left_max <= right_max) {
                // calc left side
                left_max = max(left_max, height[left]);
                ans += (left_max - height[left]);
                left++;
            } else {
                // calc right side
                right_max = max(right_max, height[right]);
                ans += (right_max - height[right]);
                right--;
            }
        }
        return ans;
    }
};
