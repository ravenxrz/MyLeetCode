//
// Created by Raven on 2021/1/21.
//
#include <vector>
#include <cassert>
#include <iostream>

using namespace std;


class Solution {
public:
    vector<int> exchange(vector<int> &nums)
    {
        if (nums.size() <= 1) return nums;
        
        int i = 0;
        int j = nums.size() - 1;
        
        
        // 执行双指针交换
        while (i < j) {
            while (i < j && (nums[i] & 1) != 0) {   //
                i++;
            }
            while (i < j && (nums[j] & 1) == 0) {
                j--;
            }
            if (i < j) {
                swap(nums[i], nums[j]);
                i++;
                j--;
            }
        }
        return nums;
    }

private:
    static void swap(int &i, int &j)
    {
        int t = i;
        i = j;
        j = t;
    }
    
};

void print_nums(const vector<int> &nums)
{
    for (auto val : nums) {
        cout << val << " ";
    }
    cout << endl;
}


void test(vector<int> &nums)
{
    static Solution sol;
    print_nums(nums);
    sol.exchange(nums);
    print_nums(nums);
    cout << endl;
}


int main()
{
    {
        // empty
        vector<int> nums{};
        test(nums);
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
        vector<int> nums{1, 3, 6, 4, 1, 2};
        test(nums);
    }
    
    {
        // odd and even  mix
        vector<int> nums{2, 3, 6, 4, 1, 5};
        test(nums);
    }
    
    return 0;
}
