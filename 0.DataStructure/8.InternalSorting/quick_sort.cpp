//
// Quick sort
//

#include "common.h"

class QuickSorter : public Sorter<int> {
    /**
     * 快速排序 复杂度O(nlog(n)) 非稳定排序算法
     * 最坏的情况，序列已经有序，此时复杂度为O(n^2)
     * 可通过修改 “选择pivot"来优化最坏情况
     * 10k数据量 0.002 s
     * 100k数据量 0.02 s
     * @param nums
     */
    void _sort(std::vector<int> &nums) override
    {
        quick_sort(nums, 0, nums.size() - 1);
    }

private:
    void quick_sort(std::vector<int> &nums, int start, int end)
    {
        if (start < 0 || end > nums.size() || start >= end) return;
        int pivot = nums[start];
        int i = start, j = end;
        while (i < j) {
            while (i < j && nums[j] >= pivot) --j;
            nums[i] = nums[j];
            while (i < j && nums[i] <= pivot) ++i;
            nums[j] = nums[i];
        }
        nums[j] = pivot;
        quick_sort(nums, start, j - 1);
        quick_sort(nums, j + 1, end);
    }
};

int main()
{
    std::vector<int> nums = {1,3,2};
    
//    std::sort(nums.rbegin(),nums.rend());     // 100k数据+反序会出现堆溢出
//    printNums(nums);
    Sorter<int> *sorter = new QuickSorter();
    sorter->sort(nums);
    printNums(nums);
    delete sorter;
    return 0;
}