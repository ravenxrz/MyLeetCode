//
// Created by a2855 on 2020/11/22.
//

#include "common.h"

using namespace std;

class HeapSorter : public Sorter<int> {
private:
    /**
     * 堆排序。 特点： 最差，平均的时间复杂度都是O(nlog(n)) 这是和快速排序相比的优点
     * 但是最初建立heap和调整heap都比较耗时
     * 10k数据量 0.004
     * 100k数据量 0.065
     *
     * @param nums
     */
    void _sort(std::vector<int> &nums) override
    {
        int remain_count = nums.size();
        // build heap 最大堆 --> 但是最后得到的是从小到大的序列。
        for (int i = 1; i < nums.size(); i++) {
            push_up(nums, i);
        }
        // heap sort
        for (int i = 0; i < nums.size(); i++) {
            // 将tree root和tree尾交换。
            // 这里的用途有两个：1. 维护最大堆的特性 2. 保证最终生成的序列是从小到大的序列
            swap(nums,remain_count-1,0);
            remain_count--;
            push_down(nums, remain_count, 0);
        }
    }

private:
    void swap(vector<int> &nums, int idx1, int idx2)
    {
        int tmp = nums[idx1];
        nums[idx1] = nums[idx2];
        nums[idx2] = tmp;
    }
    
    /**
     * 从某个pos开始push up
     * @param tree
     * @param pos
     */
    void push_up(vector<int> &tree, int pos)
    {
        int cur = pos;
        while (cur != 0) {
            int parent = (cur - 1) >> 1;
            if (tree[parent] < tree[cur]) {
                swap(tree, parent, cur);
            }
            cur = parent;
        }
    }
    
    /**
     * 从某个点开始push down
     * @param tree
     * @param len
     * @param pos
     */
    void push_down(vector<int> &tree, int len, int pos)
    {
        int cur = pos;
        while (true) {
            int lchild = cur <<  1 | 1;
            int rchild = (cur + 1) << 1;
            int max_idx = -1;
            if (rchild < len) {
                max_idx = tree[lchild] > tree[rchild] ? lchild : rchild;
            } else if (lchild < len) {
                max_idx = lchild;
            } else {
                break;
            }
            
            if (tree[cur] < tree[max_idx]) {
                swap(tree, cur, max_idx);
                cur = max_idx;
            } else {       // heap 调整完成
                break;
            }
        }
    }
};

int main()
{
    std::vector<int> nums = generateRandomNumbers<int>(100*1000, 1, 1000*1000);
//    printNums(nums);
    Sorter<int> *sorter = new HeapSorter();
    sorter->sort(nums);
//    printNums(nums);
    delete sorter;
    return 0;
}
