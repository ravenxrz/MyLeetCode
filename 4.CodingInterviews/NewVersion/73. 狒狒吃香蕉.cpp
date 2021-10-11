#include "leetcode_base.h"

class Solution {
   public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = *max_element(piles.begin(), piles.end());
        while (l < r) {
            int mid = (l + r) >> 1;
            int hours = calc(piles, mid);
			// cout << mid << ":" << hours << endl;;
            if (hours == h) {
                r = mid;
            } else if (hours < h) {
				r = mid;
            } else if (hours > h) {
                l = mid + 1;
            }
        }
		return l;
    }

   private:
    int calc(vector<int>& piles, int k) {
        int sum = 0;
        for (int i = 0; i < piles.size(); i++) {
            sum += ((piles[i] + k - 1) / k);
        }
        return sum;
    }
};

int main() {
    Solution sol;
	{
		vector<int> piles = {3, 6, 7, 11};
		cout << sol.minEatingSpeed(piles, 8) << endl;
	}
	{
		vector<int> piles = {30,11,23,4,20};
		cout << sol.minEatingSpeed(piles, 5) << endl;
	}
	{
		vector<int> piles = {30,11,23,4,20};
		cout << sol.minEatingSpeed(piles, 6) << endl;
	}
    return 0;
}