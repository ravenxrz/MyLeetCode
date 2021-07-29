//
// Created by raven on 2021/7/29.
//

class Solution {
    vector<string> ans;
public:
    vector<string> permutation(string s)
    {
        assert(!s.empty());
        ans.clear();
        do_permutation(s, 0);
        return ans;
    }

private:
    void do_permutation(string &s, int start)
    {
        if (start == s.size()) {
            ans.push_back(s);
            return;
        }
        unordered_set<char> swapped_set;
        for (int i = start; i < s.size(); i++) {
            if(swapped_set.count(s[i])) continue;
            swapped_set.insert(s[i]);
            swap(s[start], s[i]);
            do_permutation(s, start + 1);
            swap(s[start], s[i]);
        }
    }
};
