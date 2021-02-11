#include <vector>
#include <iostream>

using namespace std;


class Solution {
public:
    int reversePairs(vector<int> &nums)
    {
        ans = 0;
        if (nums.empty()) return 0;
        aux.resize(nums.size());
        mergeSort(nums, 0, nums.size() - 1);
        return ans;
    }

private:
    void mergeSort(vector<int> &nums, int start, int end)
    {
        if (start >= end) {
            return;
        }
        int mid = (start + end) >> 1;
        mergeSort(nums, start, mid);
        mergeSort(nums, mid + 1, end);
        mergeAndCount(nums, start, mid, mid + 1, end);
    }
    
    void mergeAndCount(vector<int> &nums, int s1, int e1, int s2, int e2)
    {
        // try to merge those two arrays
        int i = e1, j = e2;
        int aux_idx = e2-s1;
        while (i >= s1 && j >= s2) {
            if (nums[i] > nums[j]) {
                ans += (j - s2) + 1;
                aux[aux_idx--] = nums[i--];
            } else {
                aux[aux_idx--] = nums[j--];
            }
        }
        while (i >= s1) {
            aux[aux_idx--] = nums[i--];
        }
        while (j >= s2) {
            aux[aux_idx--] = nums[j--];
        }
        
        // copy back
        for ( i = s1; i <= e2; i++) {
            nums[i] = aux[i - s1];
        }
    }

private:
    vector<int> aux;
    int ans;
};

int main()
{
    Solution sol;
    {
        // no reverse pairs
        vector<int> nums{1, 2, 3, 4};
        cout << sol.reversePairs(nums) << '\n';
    }
    {
        // normal case
        vector<int> nums{7, 5, 6, 4};
        cout << sol.reversePairs(nums) << '\n';
    }
    return 0;
}
