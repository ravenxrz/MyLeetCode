class Solution {
public:
    int longestConsecutive(vector<int> &nums)
    {
        if (nums.empty()) return 0;
        // write code here
        unordered_set<int> uset;
        // 去重处理
        for (int val : nums) {
            uset.insert(val);
        }
        int max_len = 1;
        for (int num : uset) {
            if (uset.find(num - 1) == uset.end()) { // not found
                // so this is the first value of this sequence
                int len = 1;
                for (int delta = 1; delta < uset.size(); delta++) {
                    if (uset.find(num + delta) != uset.end()) {   // we can find num + delta in the uset
                        len++;
                    } else {
                        break;
                    }
                }
                // the consecutive is stopped
                max_len = max(max_len, len);
            }
        }
        return max_len;
    }
};
