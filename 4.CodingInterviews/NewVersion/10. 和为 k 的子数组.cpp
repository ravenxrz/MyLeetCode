#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> umap;
        umap[0] = 1;
        int asum = 0;
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            asum += nums[i];
            if (umap.count(asum - k)) {
                ans += umap[asum - k];
            }
            umap[asum]++;
        }
        return ans;
    }
};

int main() {
    Solution sol;
    {
        vector<int> nums = {1, 1, 1};
        cout << sol.subarraySum(nums, 2) << endl;
    }
    {
        vector<int> nums = {1, 2, 3};
        cout << sol.subarraySum(nums, 3) << endl;
    }
    return 0;
}