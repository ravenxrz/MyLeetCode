#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
		int ans = 0;
		int l = 0;
		int r = 0;
		long long prod = 1;
		while(r < nums.size()){
			prod *= nums[r++];
			while(prod >= k && l < r){
				prod /= nums[l++];
			}
			ans += (r - l);
		}
		return ans;
    }
};

/*
class Solution {
   public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        vector<int> dp(nums.size(), 0);
        // init
        for (int i = 0; i < nums.size(); i++) {
            dp[i] = nums[i] < k ? 1 : 0;
        }
        // calc
        long long prod = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            prod *= nums[i];
            if (prod < k) {
                dp[i] += dp[i - 1];
            } else {
                int j;
                for (j = i - dp[i - 1]; j < i; j++) {
                    prod /= nums[j];
                    if (prod < k)
                        break;
                }
                if (prod < k) {
                    dp[i] = i - j;
                }
            }
        }
        return accumulate(dp.begin(), dp.end(), 0);
    }
};
*/

int main(int argc, const char** argv) {
    Solution sol;
    {
        vector<int> nums = {10, 5, 2, 6};
        cout << sol.numSubarrayProductLessThanK(nums, 100) << endl;
    }
    {
        vector<int> nums = {1, 2, 3};
        cout << sol.numSubarrayProductLessThanK(nums, 0) << endl;
    }
    return 0;
}