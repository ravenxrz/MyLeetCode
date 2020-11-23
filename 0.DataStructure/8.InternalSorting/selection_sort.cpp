//
// Created by a2855 on 2020/11/22.
//
#include "common.h"

using namespace std;

class SelectionSorter : public Sorter {
private:
    /**
     * 选择排序, 每次循环选择最小的element。 时间复杂度 O(n^2)
     * 10k数据量 0.623s
     * 100k数据量  46.568s
     * @param nums
     */
    void _sort(vector<int> &nums) override
    {
        const int len = nums.size();
        int temp = -1;
        for (int i = 0; i < len - 1; i++) {
            for (int j = i + 1; j < len; j++) {     // find min value and its idx
                if (nums[i] > nums[j]) {
                    // swap
                    temp = nums[i];
                    nums[i] = nums[j];
                    nums[j] = temp;
                }
            }
        }
    }
};

int main()
{
    vector<int> nums = generateRandomNumbers(100 * 1000, 1, 1000 * 1000);
//    printNums(nums) ;
    
    Sorter *sorter = new SelectionSorter();
    sorter->sort(nums);
//    printNums(nums);
    
    delete sorter;
    return 0;
}