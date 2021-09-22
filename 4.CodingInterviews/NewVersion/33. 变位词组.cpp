#include "leetcode_base.h"

class Solution {
   public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> umap;
        for (int i = 0; i < strs.size(); i++) {
            string tmp = strs[i];
            sort(tmp.begin(), tmp.end());
            if (umap.count(tmp)) {
                umap[tmp].push_back(strs[i]);
            } else {
                umap[tmp] = {strs[i]};
            }
        }
		vector<vector<string>> ans;
		for(const auto& kv : umap){
			ans.push_back(kv.second);
		}
		return ans;
    }
};

/* 并查集做法, 但是最后一个case超时 */
class Solution {
   public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        if (strs.empty())
            return {};

        sort(strs.begin(), strs.end(),
             [](const string& lhs, const string& rhs) {
                 return lhs.size() < rhs.size();
             });

        int* s_union = new int[strs.size()];
        for (int i = 0; i < strs.size(); i++) {
            s_union[i] = i;
        }

        unordered_set<int> vset;
        for (int i = 1; i < strs.size(); i++) {
            vset.clear();
            for (int j = i - 1; j >= 0; j--) {
                int idx = findRoot(s_union, j);
                if (vset.count(idx))
                    continue;
                vset.insert(idx);
                if (check(strs[i], strs[idx])) {
                    s_union[i] = idx;
                    break;
                }
            }
        }

        // Build ans
        vector<vector<string>> ans;
        unordered_map<int, vector<string>> umap;
        int idx = 0;
        while (idx < strs.size()) {
            int root = findRoot(s_union, idx);
            if (umap.count(root)) {
                umap[root].push_back(strs[idx]);
            } else {
                umap[root] = {strs[idx]};
            }
            idx++;
        }
        for (const auto& kv : umap) {
            ans.push_back(kv.second);
        }

        delete[] s_union;
        s_union = nullptr;
        return ans;
    }

   private:
    int findRoot(int* s_union, int idx) {
        int ret_idx = idx;
        while (s_union[ret_idx] != ret_idx)
            ret_idx = s_union[ret_idx];
        return ret_idx;
    }

   private:
    /* str1 和 str2 是否为变位词 */
    bool check(const string& str1, const string& str2) {
        if (str1.size() != str2.size())
            return false;
        int window[26];
        memset(window, 0, sizeof(window));
        for (int i = 0; i < str1.size(); i++) {
            window[str1[i] - 'a']++;
            window[str2[i] - 'a']--;
        }
        return all_of(window, window + 26, [](int val) { return val == 0; });
    }
};

int main() {
    Solution sol;
    vector<string> in = {"eat", "tea", "tan", "ate", "nat", "bat"};
    for (const auto& vec : sol.groupAnagrams(in)) {
        for (auto val : vec) {
            cout << val << ' ';
        }
        cout << endl;
    }
    return 0;
}