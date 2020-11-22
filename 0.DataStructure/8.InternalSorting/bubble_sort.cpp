//
// Bubble sort
//

#include "common.h"

class BubbleSorter : public Sorter{
    /**
     * 冒泡排序 复杂度O(n^2)
     * 一个优化点是，当一次循环中，没有发生“交换”操作时，说明已经排好序，
     * 直接跳出循环即可
     * 10k数据量 0.738 s
     * 100k数据量 77.5 s
     * @param nums
     */
    void _sort(std::vector<int> &nums) override{
        int tmp;
        for(int i = 0; i<nums.size()-1;i++){
            bool swapped = false;
            for(int j = 0;j<nums.size()-1-i;j++){
                if(nums[j] > nums[j+1]){
                    tmp = nums[j];
                    nums[j] = nums[j+1];
                    nums[j+1] = tmp;
                    swapped = true;
                }
            }
            if(!swapped){   /* 提前终止 */
                break;
            }
        }
    }
};

int main() {
    std::vector<int> nums = generateRandomNumbers(8, 1, 10);
    printNums(nums);
    Sorter *sorter = new BubbleSorter();
    sorter->sort(nums);
//    printNums(nums);
    delete sorter;
    return 0;
}