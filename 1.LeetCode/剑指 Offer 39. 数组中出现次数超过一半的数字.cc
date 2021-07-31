//
// Created by Raven on 2021/7/31.
//
class Solution {
public:
  int majorityElement(vector<int> &nums) {
    unordered_map<int, int> umap;
    for (int val : nums) {
      umap[val]++;
    }
    int half_len = nums.size() >> 1;
    return *find_if(nums.begin(), nums.end(),
                    [&](int x) { return umap[x] > half_len; });
  }
};
