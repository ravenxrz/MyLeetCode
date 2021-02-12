#include <vector>

using namespace std;


class Solution {
public:
    vector<int> singleNumbers(vector<int> &nums)
    {
        // assert(nums.size() >= 2)
        int num = 0;
        for (int val : nums) {
            num = num ^ val;
        }
        // 找到从右起第一个为1的位置
        int offset = 0;
        while (((num >> offset) & 1) != 1) {
            offset++;
        }
        // 按offset位异或
        int num1 = 0;
        int num2 = 0;
        for (int val :nums) {
            if ((val >> offset) & 1) {
                num1 ^= val;
            } else {
                num2 ^= val;
            }
        }
        return {num1,num2};
    }
};
