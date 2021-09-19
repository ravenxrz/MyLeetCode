#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int findMaxLength(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0)
                nums[i] = -1;
        }

        unordered_map<int, int> umap;  // map number value to the index of it
        umap[0] = -1;
        int sum = 0;
        int max_len = 0;

        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if (umap.count(sum)) {
                max_len = max(max_len, i - umap[sum]);
            } else {
                umap[sum] = i;
            }
        }
        return max_len;
    }
};

int main() {
    Solution sol;
    {
        vector<int> dp = {0, 1};
        cout << sol.findMaxLength(dp) << endl;
    }
    {
        vector<int> dp = {0, 1, 0, 0, 1};
        cout << sol.findMaxLength(dp) << endl;
    }
    return 0;
}