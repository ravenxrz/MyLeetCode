#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<vector<int>> ans;

   public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        ans.clear();
        vector<Item> tmp;
        dfs(candidates, tmp, 0, target, 0);
        return ans;
    }

   private:
    struct Item {
        int val;
        int times;
        Item(int v, int t) : val(v), times(t) {}
    };

    vector<int> convert(vector<Item>& tmp) {
        vector<int> ret;
        for (auto& item : tmp) {
            for (int i = 0; i < item.times; i++) {
                ret.push_back(item.val);
            }
        }
        return ret;
    }

    void dfs(const vector<int>& candidates,
             vector<Item>& tmp,
             int cur_sum,
             int target,
             int idx) {
        if (idx == candidates.size()) {
            if (cur_sum == target) {
                ans.push_back(convert(tmp));
            }
            return;
        }

        if (cur_sum > target)
            return;
        else if (cur_sum == target) {
            ans.push_back(convert(tmp));
            return;
        } else {
            int total_times = (target - cur_sum) / candidates[idx];
            total_times = total_times * candidates[idx] < target - cur_sum
                              ? total_times + 1
                              : total_times;
            for (int i = 0; i <= total_times; i++) {
                tmp.push_back(Item(candidates[idx], i));
                dfs(candidates, tmp, cur_sum + i * candidates[idx], target,
                    idx + 1);
                tmp.pop_back();
            }
        }
    }
};

int main() {
    Solution sol;
    {
        vector<int> nums = {2, 3, 5};
        for (const auto& vec : sol.combinationSum(nums, 8)) {
            for (auto val : vec) {
                cout << val << ' ';
            }
            cout << endl;
        }
    }
    return 0;
}
