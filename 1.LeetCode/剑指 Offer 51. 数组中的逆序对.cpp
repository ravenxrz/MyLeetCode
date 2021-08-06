#include "leetcode_base.h"

class Solution {
   private:
    int ans;
    vector<int> aux;

   public:
    int reversePairs(vector<int>& nums) {
        ans = 0;
        aux.resize(nums.size());
        mergeCalc(nums, 0, nums.size() - 1);
        return ans;
    }

   private:
    void mergeCalc(vector<int>& nums, int begin, int end) {
        if (begin >= end)
            return;
        int mid = (begin + end) >> 1;
        mergeCalc(nums, begin, mid);
        mergeCalc(nums, mid + 1, end);
        mergeCalcCore(nums, begin, mid, mid + 1, end);
    }

    void mergeCalcCore(vector<int>& nums, int s1, int e1, int s2, int e2) {
        int i = e1;
        int j = e2;
        int back_idx = aux.size() - 1;
        while (i >= s1 && j >= s2) {
            if (nums[i] > nums[j]) {
                ans += (j - s2) + 1;
                aux[back_idx--] = nums[i--];
            } else {
                aux[back_idx--] = nums[j--];
            }
        }
        while (i >= s1) {
            aux[back_idx--] = nums[i--];
        }
        while (j >= s2) {
            aux[back_idx--] = nums[j--];
        }
        // Copy back
        for (int k = s1; k <= e2; k++) {
            nums[k] = aux[++back_idx];
        }
    }
};

int main() {
    Solution sol;
    vector<int> nums = {3, 7, 6, 8, 5};
    cout << sol.reversePairs(nums) << endl;
    return 0;
}