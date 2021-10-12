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
    return 0;
}