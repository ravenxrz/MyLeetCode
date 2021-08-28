#include "leetcode_base.h"

class Solution {
   public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> num2freq;
        auto compare = [](const pair<int, int>& p1, const pair<int, int>& p2) {
            return p1.first < p2.first;
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       decltype(compare)>
            max_heap(compare);

        // First, scan nums, and store it to num2freq hashmap
        for (auto val : nums) {
            num2freq[val]++;
        }
        // Second, scan num2freq and store (freq, number) tuple into max_heap
        for (const auto& kv : num2freq) {
            max_heap.push({kv.second, kv.first});
        }
        // Third, pop k times from max_heap
        vector<int> ans;
        while (!max_heap.empty() && k != 0) {
            ans.push_back(max_heap.top().second);
            max_heap.pop();
            k--;
        }
        return ans;
    }
};

int main() {
    Solution sol;
    {
        vector<int> nums = {1, 1, 1, 2, 2, 3};
        int k = 2;
        for (auto val : sol.topKFrequent(nums, k)) {
            cout << val << endl;
        }
    }
    return 0;
}