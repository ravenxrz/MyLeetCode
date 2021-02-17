/**
 * 快速排序
 * 时间复杂度：
 * 最好: O(nlogn)
 * 最差： O(n^2) 条件：已经有序, 退化到冒泡排序时
 * 平均: O(nlogn)
 * 空间复杂度:
 * 最好： O(logn)
 * 最差: O(n)。 退化到冒泡排序时
 * 稳定性:
 * 不稳定
 */
#include "data_generator.h"
#include <vector>

using namespace std;

static void quick_sort_core(vector<int> &data, int start, int end);

static void quick_sort(vector<int> &data)
{
    quick_sort_core(data, 0, data.size() - 1);
}

void quick_sort_core(vector<int> &data, int start, int end)
{
    if (start < 0 || end >= data.size() || start > end) return;
    int pivot = data[start];
    int i = start, j = end;
    while (i < j) {
        while (i < j && pivot <= data[j]) j--;
        data[i] = data[j];
        while (i < j && pivot >= data[i]) i++;
        data[j] = data[i];
    }
    data[i] = pivot;
    quick_sort_core(data, start, i - 1);
    quick_sort_core(data, i + 1, end);
}

int main()
{
    vector<int> nums = DataGenerator::generate(100, 0, 100);
    printData(nums);
    quick_sort(nums);
    printData(nums);
    return 0;
}