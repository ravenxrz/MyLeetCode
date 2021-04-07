//
// Created by raven on 2021/4/1.
//

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        unordered_map<string, int> str_map;
        vector<vector<string>> ans;
        
        int idx_offset = 0;
        for (int i = 0; i < strs.size(); ++i) {
            auto str = strs[i];
            sort(str.begin(), str.end());
            if (str_map.count(str)) {
                int idx = str_map[str];
                ans[idx].push_back(strs[i]);
            } else {
                str_map[str] = idx_offset++;
                ans.push_back({strs[i]});
            }
        }
        
        return ans;
    }
    
};