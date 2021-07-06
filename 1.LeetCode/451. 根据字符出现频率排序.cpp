#include "leetcode_base.h"

class Solution
{
public:
    string frequencySort(string s)
    {
        std::unordered_map<char, int> umap;

        // count while iteratoring s
        for (int i = 0; i < s.size(); i++)
        {
            ++umap[s[i]];
        }

        vector<pair<char, int>> alphabets;
        for(const auto& kvp : umap){
            alphabets.push_back(pair<char, int>(kvp.first, kvp.second));
        }

        // sort
        sort(alphabets.begin(), alphabets.end(), [](const pair<char, int> &p1, const pair<char, int> &p2)
             { return p1.second >= p2.second; });

        // Construct ans from "alphabets"
        string ans(s.size(), ' ');
        int idx = 0;
        for (const auto &pair : alphabets)
        {
            for (int i = 0; i < pair.second; i++)
            {
                ans[idx++] = pair.first;
            }
        }
        return ans;
    }
};

int main()
{
    Solution sol;
    cout << sol.frequencySort("tree") << endl;
    cout << sol.frequencySort("cccaaa") << endl;
    cout << sol.frequencySort("Aabb") << endl;
    return 0;
}