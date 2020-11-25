//
// Created by a2855 on 2020/11/25.
// 桶排序， 桶排序有多种实现方式。
// GeeksforGeeks 给了一种[0,1]之间的浮点数排序方式，本文参考它实现
// 参考链接：
// 1.
// 2. https://blog.csdn.net/daaikuaichuan/article/details/80656907
//

#include "common.h"
using namespace std;

class BucketSorter : public Sorter<float>{
    /**
     * [0,1] 浮点数 桶排序算法 稳定排序. 最好O(n) 最坏O(n^2)
     *  桶排序的时间复杂度，取决与对各个桶之间数据进行排序的时间复杂度，因为其它部分的时间复杂度都为O(n)。
     * 10k 数据量 0.004s
     * 100k 数据量 0.074s
     * @param nums
     */
    void _sort(vector<float> &nums) override
    {
        const unsigned int len = nums.size();
        // 1. 创建n个桶
        vector<float> buckets[len+1];
        // 2. 插入n个数字到n个桶
        for(int i = 0;i<len;i++){
            int bidx = static_cast<int>(nums[i] * len);
            buckets[bidx].push_back(nums[i]);
        }
        // 3. 依赖其他排序算法排序
        for(int i = 0;i<len+1;i++){
            std::sort(buckets[i].begin(),buckets[i].end());
        }
        // 4. 重新组合
        int counter = 0;
        for(int i = 0;i<len+1;i++){
            for(float val : buckets[i]){
                nums[counter++] = val;
            }
        }
    }
};

int main(){
    vector<float> nums = generateRandomNumbers<float>(100*1000,0,1);
//    printNums(nums);
    Sorter<float>* sorter = new BucketSorter();
    sorter->sort(nums);
    delete sorter;
//    printNums(nums);
    return 0;
}