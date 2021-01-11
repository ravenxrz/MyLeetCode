/*
 * @lc app=leetcode.cn id=75 lang=cpp
 *
 * [75] 颜色分类
 */
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

// @lc code=start
class Solution {
public:
    void sortColors(vector<int> &nums)
    {
        if (nums.empty()) return;
        if (nums.size() <= 3) {
            sort(nums.begin(), nums.end());
            return;
        }
        int idx[3];
        fill(begin(idx), end(idx), -1);
        
        // 设置第0位为0
        if (nums[0] != 0) {
            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] == 0) {
                    swap(nums[0], nums[i]);
                    idx[0] = 0;
                    break;
                }
            }
        } else {
            idx[0] = 0;
        }
        // 设置第1位为1
        if (nums[1] != 1) {
            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] == 1) {
                    swap(nums[1], nums[i]);
                    idx[1] = 1;
                    break;
                }
            }
        } else {
            idx[1] = 1;
        }
        // 设置第2位为2
        if (nums[2] != 2) {
            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] == 2) {
                    swap(nums[2], nums[i]);
                    idx[2] = 2;
                    break;
                }
            }
        } else {
            idx[2] = 2;
        }
        
        // 算法开始
        for (int i = 0; i < nums.size(); i++) {
            switch (nums[i]) {
                case 0:
                    // 寻找 1
                    if (idx[1] != -1 && i > idx[1]) {
                        swap(nums[i], nums[idx[1]]);
                        // update idx[1]
                        next_idx(idx, 1, idx[1] + 1, i, nums);
                        i--;
                    }
                    break;
                case 1:
                    // 寻找2
                    if (idx[2] != -1 && i > idx[2]) {
                        swap(nums[i], nums[idx[2]]);
                        // update idx[2]
                        next_idx(idx, 2, idx[2] + 1, i, nums);
                        i--;
                    }
                    break;
                case 2:
                    break;
                default:
                    throw exception();
            }
        }
    }

private:
    static void next_idx(int *idx, int i, int start, int end, const vector<int> &nums)
    {
        for (int cur = start; cur <= end; i++) {
            if (nums[cur] == i) {
                idx[i] = cur;
                return;
            }
        }
        idx[i] = -1;
    }
    
    static void swap(int &i, int &j)
    {
        int t = i;
        i = j;
        j = t;
    }
};
// @lc code=end

void print_nums(const vector<int> &nums)
{
    for (auto val : nums) {
        cout << val << " ";
    }
    cout << endl;
}

int main()
{
    Solution sol;
    
    // empty test
    {
        vector<int> nums{};
        sol.sortColors(nums);
        print_nums(nums);
    }
    
    // one type
    {
        vector<int> nums{0, 0, 0};
        sol.sortColors(nums);
        print_nums(nums);
    }
    
    // two types
    {
        vector<int> nums{0, 1, 0};
        sol.sortColors(nums);
        print_nums(nums);
    }
    {
        vector<int> nums{0, 2, 0};
        sol.sortColors(nums);
        print_nums(nums);
    }
    {
        vector<int> nums{2, 2, 1};
        sol.sortColors(nums);
        print_nums(nums);
    }
    
    // three types
    {
        vector<int> nums{0, 1, 0, 2, 1, 0};
        sol.sortColors(nums);
        print_nums(nums);
    }
    
    {
        vector<int> nums{0, 1, 0, 2, 1, 0,1,2,0,0,1,1,2,2,0,0,0};
        sol.sortColors(nums);
        print_nums(nums);
    }
    
    
    return 0;
}
