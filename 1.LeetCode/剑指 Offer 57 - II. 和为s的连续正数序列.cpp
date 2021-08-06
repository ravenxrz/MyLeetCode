#include "leetcode_base.h"

class Solution {
   public:
    vector<vector<int>> findContinuousSequence(int target) {
        int left = 1;
        int right = 2;
        vector<vector<int>> ans;
        int half = (target + 1) >> 1;
        while (right <= half) {
            int sum = (left + right) * (right - left + 1) >> 1;
            if (sum == target) {
                vector<int> tmp;
                tmp.reserve(right - left + 1);
                for (int val = left; val <= right; val++) {
                    tmp.push_back(val);
                }
                ans.emplace_back(tmp);
                // Move forward
                left++;
                right++;
            } else if (sum < target) {
                left++;
            } else if (sum > target) {
                right++;
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    for (auto& vec : sol.findContinuousSequence(9)) {
        for (auto val : vec) {
            cout << val << ' ';
        }
        cout << endl;
    }
    return 0;
}
#include "leetcode_base.h"

class Solution {
   public:
    vector<vector<int>> findContinuousSequence(int target) {
        int left = 1;
        int right = 2;
        vector<vector<int>> ans;
        int half = (target + 1) >> 1;
        while (right <= half) {
            int sum = (left + right) * (right - left + 1) >> 1;
            if (sum == target) {
                vector<int> tmp;
                tmp.reserve(right - left + 1);
                for (int val = left; val <= right; val++) {
                    tmp.push_back(val);
                }
                ans.emplace_back(tmp);
                // Move forward
                left++;
                right++;
            } else if (sum < target) {
                left++;
            } else if (sum > target) {
                right++;
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    for (auto& vec : sol.findContinuousSequence(9)) {
        for (auto val : vec) {
            cout << val << ' ';
        }
        cout << endl;
    }
    return 0;
}