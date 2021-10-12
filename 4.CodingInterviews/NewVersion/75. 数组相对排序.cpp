#include "leetcode_base.h"

class Solution {
   public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int, int> umap;
        for (auto val : arr1) {
            umap[val]++;
        }

        vector<int> ans;
        for (auto val : arr2) {
            if (umap.count(val)) {
                ans.insert(ans.end(), umap[val], val);
                umap.erase(val);
            }
        }
        for (auto& kv : umap) {
            ans.insert(ans.end(), kv.second, kv.first);
        }

        return ans;
    }
};
