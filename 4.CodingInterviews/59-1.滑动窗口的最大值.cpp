#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        if (nums.empty()) return {};
        if (k == 1) return nums;
        vector<int> ans;
        ans.reserve(nums.size() - k + 1);
        // assert(nums.size() >= k)
        int lastMax = nums[0];
        int left = 0, right = k - 1;
        // 计算第一个窗口
        for (int i = 1; i < k; i++) {
            lastMax = max(lastMax, nums[i]);
        }
        ans.push_back(lastMax);
        // 计算剩余的窗口
        while (right < nums.size()) {
            left++;
            right++;
            if (right == nums.size()) break;
            if (nums[right] >= lastMax) {
                lastMax = nums[right];
                ans.push_back(lastMax);
            } else if (nums[left - 1] != lastMax) {
                ans.push_back(lastMax);
            } else {  // nums[left-1] == lastMax && nums[right] < lastMax
                // re calculate
                lastMax =  nums[left];
                for (int i = left+1; i <= right; i++) {
                    lastMax = max(nums[i], lastMax);
                }
                ans.push_back(lastMax);
            }
        }
       return ans;
    }
};
