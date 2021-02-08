#include <vector>
#include <unordered_map>
#include <algorithm>
#include <cassert>
#include <iostream>

using namespace std;


class Solution {
public:
    int majorityElement(vector<int> &nums)
    {
        int result = -1;
        int times = 0;
        for (int val : nums) {
            if (times == 0) {
                result = val;
                times = 1;
            } else if (val == result) {
                times++;
            } else {
                times--;
            }
        }
        return result;
    }
};

void print_vec(const vector<int> &nums)
{
    for (auto val : nums) {
        cout << val << ' ';
    }
    cout << '\n';
}

int main()
{
    Solution sol;
//    {
//        vector<int> vec{};
//        cout << sol.majorityElement(vec) << '\n';
//    }
//
//    {
//        vector<int> vec{1};
//        cout << sol.majorityElement(vec) << '\n';
//    }
//
//    {
//        vector<int> vec{1, 2, 3, 2, 2, 2, 5, 4, 2};
//        cout << sol.majorityElement(vec) << '\n';
//    }
    
    {
        vector<int> vec{47, 47, 72, 47, 72, 47, 79, 47, 12, 92, 13, 47, 47, 83, 33, 15, 18, 47, 47, 47, 47, 64, 47, 65,
                        47, 47, 47, 47, 70, 47, 47, 55, 47, 15, 60, 47, 47, 47, 47, 47, 46, 30, 58, 59, 47, 47, 47, 47,
                        47, 90, 64, 37, 20, 47, 100, 84, 47, 47, 47, 47, 47, 89, 47, 36, 47, 60, 47, 18, 47, 34, 47, 47,
                        47, 47, 47, 22, 47, 54, 30, 11, 47, 47, 86, 47, 55, 40, 49, 34, 19, 67, 16, 47, 36, 47, 41, 19,
                        80, 47, 47, 27};
        cout << sol.majorityElement(vec) << '\n';
        sort(vec.begin(), vec.end());
    }
    
    return 0;
}
