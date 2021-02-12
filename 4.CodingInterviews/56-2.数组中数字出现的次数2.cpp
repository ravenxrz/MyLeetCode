#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int> &nums)
    {
        int bitsNum = sizeof(int)*8;
        vector<short> record(bitsNum, 0);
        int ans = 0;
        
        // count
        for (int val : nums) {
            for (int i = 0; i < bitsNum; i++) {
                if ((val >> i) & 1) {
                    record[i]++;
                }
            }
        }
        // check whether the record[i] is 3N?
        for (int i = 0; i < bitsNum; i++) {
            if (record[i] % 3) {
                ans |= (1 << i);
            }
        }
        return ans;
    }
};

int main(){
    Solution sol;
    {
        vector<int> nums{3,4,3,3};
        cout << sol.singleNumber(nums);
    }
    return 0;
}
