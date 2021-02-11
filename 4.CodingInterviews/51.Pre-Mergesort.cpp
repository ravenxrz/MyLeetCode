//
// Created by Raven on 2021/2/11.
//
#include <iostream>
#include <vector>
#include <cassert>

using namespace std;

class MergeSorter {
public:
    MergeSorter()
    {
    
    }
    
    void doSort(vector<int> &nums)
    {
        if (nums.empty()) return;
        aux.resize(nums.size());
        mergeSort(nums, 0, nums.size() - 1);
    }

private:
    void mergeSort(vector<int> &nums, int start, int end)
    {
        if (start >= end) return;
        int mid = (start + end) / 2;
        mergeSort(nums, start, mid);
        mergeSort(nums, mid + 1, end);
        merge(nums, start, mid, mid + 1, end);
    }
    
    void merge(vector<int> &nums, int s1, int e1, int s2, int e2)
    {
        int i = s1, j = s2;
        int aux_idx = 0;
        while (i <= e1 && j <= e2) {
            if (nums[i] <= nums[j]) {
                aux[aux_idx++] = nums[i++];
            } else {
                aux[aux_idx++] = nums[j++];
            }
        }
        while (i <= e1) {
            aux[aux_idx++] = nums[i++];
        }
        while (j <= e2) {
            aux[aux_idx++] = nums[j++];
        }
        // copy back
        for (int k = s1; k <= e2; k++) {
            nums[k] = aux[k - s1];
        }
    }

private:
    vector<int> aux;
};

void generate_random_nums(vector<int> &nums, int n, int start, int end)
{
    assert(n >= 0);
    nums.reserve(n);
    for (int i = 0; i < n; i++) {
        double base_value = double(rand()) / RAND_MAX;
        nums.push_back(base_value * (end - start)+ start);
    }
}


int main()
{
    MergeSorter sorter;
    {
        vector<int> nums;
        generate_random_nums(nums, 100, 1, 1000);
        sorter.doSort(nums);
        // print
        for (int val : nums) {
            cout << val << ' ';
        }
        cout << '\n';
    }
    return 0;
}

