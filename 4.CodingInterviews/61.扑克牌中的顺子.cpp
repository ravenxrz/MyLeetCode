#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool isStraight(vector<int> &nums)
    {
        
        sort(nums.begin(), nums.end());
        int ghost_num = 0;
        int start = 0;
        
        while (start < nums.size() && nums[start] == 0) {
            ghost_num++;
            start++;
        }
        // assert(ghost_num <= 2);
        for (; start + 1 < nums.size(); start++) {
            if (nums[start] + 1 != nums[start + 1]) {
                if (ghost_num == 0) return false;
                ghost_num--;
            }
        }
        return true;
    }
};