#include <bits/stdc++.h>
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
                ans += left_max - height[left];
                left++;
            } else {
                // calc right side
                right_max = max(right_max, height[right]);
                ans += (right_max - height[right]);
                right++;
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    {
        vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
        cout << sol.trap(height) << endl;
    }
    return 0;
}