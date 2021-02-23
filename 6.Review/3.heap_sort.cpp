
/**
 * 堆排序
 * 时间复杂度：
 * 最好: O(nlogn)
 * 最差：O(nlogn)
 * 平均: O(nlogn)
 * 空间复杂度:
 * O(1)
 * 稳定性:
 * 不稳定
 */

#include "data_generator.h"
#include <vector>

using namespace std;


/**
 * 从idx开始push up
 * @param nums
 * @param idx
 */
static void push_up(vector<int> &nums, int idx)
{
    if (idx == 0) return;
    int parent_idx = (idx - 1) >> 1;
    if (nums[parent_idx] > nums[idx]) {
        // swap
        int tmp = nums[parent_idx];
        nums[parent_idx] = nums[idx];
        nums[idx] = tmp;
        push_up(nums, parent_idx);
    }
}

/**
 * 从idx开始push up
 * @param nums
 * @param idx
 */
static void push_down(vector<int> &nums, int idx)
{
    int lchild = (idx << 1) | 1;
    int rchild = (idx + 1) << 1;
    int swap_idx = -1;
    
    if (lchild < nums.size() && rchild < nums.size()) {
        swap_idx = nums[lchild] > nums[rchild] ? rchild : lchild;
    } else if (lchild < nums.size()) {
        swap_idx = lchild;
    }else{
        return;
    }
    
    if (nums[idx] > nums[swap_idx]) {
        int tmp = nums[idx];
        nums[idx] = nums[swap_idx];
        nums[swap_idx] = tmp;
        push_down(nums, swap_idx);
    }
}

void add(vector<int> &heap, int val)
{
    heap.push_back(val);
    push_up(heap, heap.size() - 1);
}

int top(const vector<int> &heap)
{
    if (heap.empty()) throw exception();
    return heap.front();
}

void pop(vector<int> &heap)
{
    if (heap.empty()) return;
    heap[0] = heap[heap.size() - 1];
    heap.resize(heap.size() - 1);
    push_down(heap, 0);
}


int main()
{
    vector<int> nums = DataGenerator::generate(50, 1, 100);
    printData(nums);
    
    vector<int> heap;
    for (int i = 0; i < nums.size(); i++) {
        add(heap, nums[i]);
    }
    // pop sort
    while (!heap.empty()) {
        cout << top(heap) << ' ';
        pop(heap);
    }
    return 0;
}