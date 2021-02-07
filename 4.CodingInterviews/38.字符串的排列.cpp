#include <string>
#include <vector>
#include <set>

using namespace std;


class Solution {
public:
    vector<string> permutation(string s)
    {
        swap_permutation(s,0);
        return ans;
    }

private:
    void swap_permutation(string &s, int idx)
    {
        if (idx == s.size()) {
            ans.push_back(s);
            return;
        }
        set<char> added_set;
        for (int i = idx; i < s.size(); i++) {
            if(added_set.find(s[i]) !=added_set.end()) {
                continue;
            }
            added_set.insert(s[i]);
            swap(s[idx], s[i]);
            swap_permutation(s, idx + 1);
            swap(s[idx], s[i]);
        }
    }
    
    void swap(char &i, char &j)
    {
        char t = i;
        i = j;
        j = t;
    }

private:
    vector<string> ans;
};
