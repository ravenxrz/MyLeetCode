//
// Created by a2855 on 2020/11/23.
// 归并排序
//

#include "common.h"

using namespace std;

class MergeSorter : public Sorter {
private:
    /**
     * merge sort O(nlogn)级别排序算法，相对于快速和堆排序来说，优点在于是稳定排序
     * 确定在于需要额外O(n)的辅助空间
     * 10k 数据量 0.003
     * 100k 数据量 0.038
     * @param nums
     */
    void _sort(vector<int> &nums) override
    {
        aux_space.resize(nums.size());
        merge_sort(nums, 0, nums.size() - 1);
    }

    void merge_sort(vector<int> &nums, int start, int end)
    {
        if (start == end) return;
        int mid = (start + end) / 2;
        merge_sort(nums, start, mid);
        merge_sort(nums, mid + 1, end);
        merge(nums, start, mid, end);
    }
    
    /**
     * merge [s1,e1],[e1+1,e2] 两段序列
     * @param nums  整个序列
     * @param s1  第一段序列start
     * @param e1  第一段序列end
     * @param e2  第二段序列end
     */
    void merge(vector<int> &nums, int s1, int e1, int e2)
    {
        int idx = 0;
        int i = s1,j = e1+1;
        
        // 归并排序
        while (i <= e1 && j <= e2) {
            if (nums[i] < nums[j]) {
                aux_space[idx++] = nums[i]; i++;
            } else {
                aux_space[idx++] = nums[j]; j++;
            }
        }
        while(i <= e1){
            aux_space[idx++] = nums[i]; i++;
        }
        while(j <= e2){
            aux_space[idx++] = nums[j]; j++;
        }
        
        // 拷贝回去
        for(int pos = s1; pos <= e2; pos++){
            nums[pos] = aux_space[pos - s1];
        }
    }

private:
    vector<int> aux_space;      // merge sort辅助空间
};

int main()
{
    std::vector<int> nums = generateRandomNumbers(100*1000, 1, 1000*1000);
//    printNums(nums);
    Sorter *sorter = new MergeSorter();
    sorter->sort(nums);
//    printNums(nums);
    delete sorter;
    return 0;
}

