//
// Created by Raven on 2021/1/21.
//
#include <vector>
#include <cassert>

using namespace std;


class Solution {
public:
    vector<int> exchange(vector<int> &nums)
    {
        if (nums.size() <= 1) return;
        
        int odd_idx = 0;
        int even_idx = nums.size();
        
        // 保证第一个元素是奇数
        if ((nums[odd_idx] & 1) != 1) {
            for (int i = 1; i < nums.size(); i++) {
                if ((nums[i] & 1) == 1) {
                    swap(nums[odd_idx], nums[i]);
                    break;
                }
            }
        }
        assert((nums[odd_idx] & 1) == 1);
        odd_idx++;
        
        // 保证第二个元素是偶数
        if ((nums[even_idx] & 1) != 0) {
            for (int i = even_idx - 1; i >= 0; i--) {
                if ((nums[i] & 1) == 0) {
                    swap(nums[even_idx], nums[i]);
                    break;
                }
            }
        }
        assert((nums[even_idx] & 1) == 0);
        even_idx--;
        
        // 执行双指针交换
        while (odd_idx < even_idx) {
            // test odd
            while (odd_idx < even_idx && (nums[odd_idx] & 1) == 1) {
                odd_idx++;
            }
            // test even
            while (odd_idx < even_idx && (nums[even_idx] & 1) == 0) {
                even_idx--;
            }
            if (odd_idx < even_idx) {
                swap(nums[odd_idx], nums[even_idx]);
                odd_idx++;
                even_idx--;
            }
        }
    }

private:
    
    void swap(int &i, int &j)
    {
        int t = i;
        i = j;
        j = t;
    }
    
    void print_nums(const vector<int> &nums)
    {
        for (auto val : nums) {
            cout << val << " ";
        }
        cout << endl;
    }
    
    void test(vector<int> &nums)
    {
        print_nums(nums);
        sol.exchange(nums);
        print_nums(nums);
        cout << endl;
    }
    
};


int main()
{
    Solution sol;
    {
        // empty
        vector<int> nums{};
        test(nums)
    }
    
    {
        // only odd
        vector<int> nums{1, 3, 5};
        test(nums);
    }
    
    
    {
        // only even
        vector<int> nums{2, 4, 6};
        test(nums);
    }
    
    
    {
        // odd and even  mix
        vector<int> nums{1, 3, 6, 4, 1, 2}
        test(nums);
    }
    
    {
        // odd and even  mix
        vector<int> nums{2, 3, 6, 4, 1, 5}
        test(nums);
    }
    
    return 0;
}
