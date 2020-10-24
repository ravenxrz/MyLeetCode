#include <vector>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;


class Solution {
public:
    
    vector<int>::iterator upper(vector<int> &nums, vector<int>::iterator first, vector<int>::iterator last, int val)
    {
        int min_val = 0x7fffffff;
        auto min_iter = last + 1;
        for (auto iter = first; iter != last + 1; iter++) {
            if (*iter > val && min_val > *iter) {
                min_val = *iter;
                min_iter = iter;
            }
        }
        return min_iter;
    }
    
    bool _nextPermutation(vector<int> &nums, int start, int end)
    {
        if (start == end) {
            return false;
        }
        
        auto start_iter = nums.begin() + start;
        auto end_iter = nums.begin() + end;
        auto max_iter = max_element(start_iter, end_iter + 1);
        
        if (max_iter == end_iter && max_iter != start_iter) {  // 最后一个元素 & 不是第一个元素
            // 和前一个位置交换
            iter_swap(max_iter - 1, max_iter);
            return true;
        }
        
        // 看 max_iter 右边区间，是否存在子排列
        if (_nextPermutation(nums, max_iter + 1 - nums.begin(), end))  // 有子排列
            return true;
        
        // 准备交换 max_iter 左边第一个元素和 max_iter 右边区间的某个元素，所以要保证 max_iter 左边第一个元素位置没有越界
        if (max_iter == nums.begin())
            return false;
        
        // 现在可以交换 max_iter 左边第一个元素和 max_iter 右边区间的某个元素
        auto max_prev_loc = (max_iter - 1);
        // 找到第一个比 max_prev_loc_val 大的元素
        auto max_prev_loc_val_upper = upper(nums, max_iter + 1, end_iter, *max_prev_loc);
        if (max_prev_loc_val_upper != end_iter + 1) {   // 找得到
            if (max_iter == start_iter) {     // 如果max_iter 在当前处理的区间的首位，则不能交换
                return false;
            }
            /**
              * 举个例子：
              * 3 5 4 2 1
              * max_iter --> 5
              * max_prev_loc --> 3
              * 所以 max_prev_loc_val_upper -->4
              * 首先交换 3和4，得到 4,5,[3,2,1]
              * 对[5,3,2,1]排列即可
              */
            iter_swap(max_prev_loc, max_prev_loc_val_upper);
            sort(max_iter, end_iter + 1);
            return true;
        } else { // 找不到upper bound
            if (max_iter == start_iter) {  // 如果max_iter 在当前处理的区间的首位，则不能交换
                return false;
            }
            /**
             * 举个例子：
             * 4 5 3 2 1
             * max_iter --> 5
             * max_prv_loc --> 4
             * [3,1,2] 都比 4小
             * 交换 4和5，得到
             * 5 4 3 1 2
             * 排序[4,3,1,2]
             * 5 1 2 3 4
             */
            iter_swap(max_prev_loc, max_iter);
            sort(max_iter, end_iter + 1);
            return true;
        }
    }
    
    void nextPermutation(vector<int> &nums)
    {
        if (nums.empty())
            return;
        
        // nums是最大元素，回归到最小元素
        bool is_max = true;
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums.at(i) < nums.at(i + 1)) {
                is_max = false;
                break;
            }
        }
        if (is_max) {
            sort(nums.begin(), nums.end());
            return;
        }
        
        // 其余情况，分治处理
        _nextPermutation(nums, 0, nums.size() - 1);
    }
};


int main()
{
//    vector<int> vec{0,1,2,3,4,5};     pass
//    vector<int> vec{5,4,3,2,1,0};     pass
//    vector<int> vec{4,5,3,2,1,0};   //       pass
//    vector<int> vec{5,3,2,4,1,0};
    vector<int> vec{2, 2, 7, 5, 4, 3, 2, 2, 1};
    Solution sol;
    sol.nextPermutation(vec);
    for (const int val : vec) {
        cout << val << " ";
    }
    cout << endl;
    return 0;
}