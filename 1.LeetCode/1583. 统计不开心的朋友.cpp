#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int unhappyFriends(int n, vector<vector<int>> &preferences, vector<vector<int>> &pairs)
    {
        int ans = 0;
        // build relationship map
        unordered_map<int, int> relation_map;
        for (const auto &pair : pairs) {
            relation_map[pair[0]] = pair[1];
            relation_map[pair[1]] = pair[0];
        }
        
        // traverse pairs to calc ans
        for (const auto &pair : pairs) {
            if (!areUHappy(pair[0], preferences, relation_map)) {
                ++ans;
            }
            if (!areUHappy(pair[1], preferences, relation_map)) {
                ++ans;
            }
        }
        return ans;
    }
    
    bool areUHappy(int person, const vector<vector<int>> &preferences, const unordered_map<int, int> &relation_map)
    {
        
        int target_pair = relation_map.at(person);
        int pair_dist =
                find(preferences[person].begin(), preferences[person].end(), target_pair) - preferences[person].begin();
        if (pair_dist == 0) return true;        // must be happy
        // check [0--pair_dist) friends are happy or not
        for (int i = 0; i < pair_dist; ++i) {
            int cur = preferences[person][i];
            int cur_pair = relation_map.at(cur);
            for (int j = 0; preferences[cur][j] != cur_pair; ++j) {
                if (preferences[cur][j] == person) return false;        // unhappy
            }
        }
        return true;        // happy
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> preferences = {
            {1, 2, 3},
            {3, 2, 0},
            {3, 1, 0},
            {1, 2, 0}
    };
    vector<vector<int>> pairs = {
            {0, 1},
            {2, 3}
    };
    cout << sol.unhappyFriends(4,preferences,pairs) << endl;
    return 0;
}
