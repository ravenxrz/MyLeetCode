//
// 基数排序-非比较型排序算法， 利用多关键字对逻辑单关键字进行排序
// 如数字 123 . 逻辑但关键字为123. 多关键字为 "1" "2" "3"
// 一般来说，有两种排序方法， 从最高位往低位排序(MSD)， 从最低位往高位排序(LSD)
//

#include "common.h"

using namespace std;

class RadixSorter : public Sorter<int> {
    
    /**
     * 基数排序，稳定排序算法。 时间复杂度：
     * O(d(n+rd))
     * d 代表每个逻辑关键字中的 关键字个数
     * n 代表输入元素个数
     * rd 代表关键字取值范围，这里就是桶的个数
     *
     * 10k 数据量 0.003 s
     * 100k 数据量 0.036 s
     * @param nums
     */
    void _sort(vector<int> &nums) override
    {
        // 数字桶 10个
        vector<int> buckets[10];
        const int loop_num = getMaxDigits(nums);
        
        for (int i = 0; i < loop_num; i++) {
            allocate(buckets, nums, i);
            collect(buckets, nums);
            clear(buckets);
        }
    }
    
    int getMaxDigits(vector<int> &nums)
    {
        auto max_elem = *max_element(nums.begin(), nums.end());
        int counter = 0;
        while (max_elem != 0) {
            counter++;
            max_elem /= 10;
        }
        return counter;
    }
    
    /**
     * 取得num的第i位。 i=0表示个位， i=1表示十位
     * @param nums
     * @param i
     * @return
     */
    int getDigit(int num, int i)
    {
        assert(i >= 0);
        int result = 0;
        do {
            // 提前终止
            if (num == 0) return 0;
            result = num % 10;
            num /= 10;
            i--;
        } while (i != -1);
        return result;
    }
    
    /**
     * 分配
     * @param buckets
     * @param nums
     * @param i 第几次分配
     */
    void allocate(vector<int> buckets[10], vector<int> &nums, int i)
    {
        // 分配
        for (int &num : nums) {
            int bidx = getDigit(num, i);
            buckets[bidx].push_back(num);
        }
    }
    
    /**
     * 回收
     * @param buckets
     * @param nums
     * @require 这里假定了buckets数组长度为10
     */
    void collect(vector<int> buckets[10], vector<int> &nums)
    {
        int counter = 0;
        for (int i = 0; i < 10; i++) {
            for (int val : buckets[i]) {
                nums[counter++] = val;
            }
        }
    }
    
    void clear(vector<int> buckets[10]){
        for(int i = 0;i<10;i++){
            buckets[i].clear();
        }
    }
    
};

int main()
{
    vector<int> nums = generateRandomNumbers<int>(100*1000, 1, 1000*1000);
//    printNums(nums);
    Sorter<int> *sorter = new RadixSorter();
    sorter->sort(nums);
//    printNums(nums);
    delete sorter;
    return 0;
}
