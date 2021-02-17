/**
 * 归并排序
 * 时间复杂度：
 * 最好: O(nlogn)
 * 最差：O(nlogn)
 * 平均: O(nlogn)
 * 空间复杂度:
 * O(n)
 * 稳定性:
 * 稳定
 */

#include "data_generator.h"
#include <vector>

using namespace std;

static void merge(vector<int> &nums, int s1, int e1, int s2, int e2)
{
    // need an auxiliary space　O(n)
    vector<int> aux(e2 - s1 + 1);
    int idx = 0;
    int i = s1, j = s2;
    while (i <= e1 && j <= e2) {
        if (nums[i] <= nums[j]) {
            aux[idx++] = nums[i++];
        } else {
            aux[idx++] = nums[j++];
        }
    }
    while (i <= e1) {
        aux[idx++] = nums[i++];
    }
    while (j <= e2) {
        aux[idx++] = nums[j++];
    }
    // copy back
    for (int k = 0; k < aux.size(); ++k) {
        nums[k + s1] = aux[k];
    }
}

static void merge_sort_core(vector<int> &nums, int start, int end)
{
    if (start < 0 || end >= nums.size() || start >= end) return;
    // split
    int mid = (start + end) >> 1;
    merge_sort_core(nums, start, mid);
    merge_sort_core(nums, mid + 1, end);
    merge(nums, start, mid, mid + 1, end);
}

static void merge_sort(vector<int> &nums)
{
    merge_sort_core(nums, 0, nums.size() - 1);
}

int main()
{
    vector<int> nums = DataGenerator::generate(1000, 1, 1000);
    printData(nums);
    merge_sort(nums);
    printData(nums);
    return 0;
}