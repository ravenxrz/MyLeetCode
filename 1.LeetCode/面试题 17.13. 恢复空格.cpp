//
// Created by Raven on 2021/3/22.
//

class Solution {
public:
    int respace(vector<string> &dictionary, string sentence)
    {
        unordered_set<string> hash_set;
        for (auto &str : dictionary) {
            hash_set.insert(str);
        }
        
        vector<int> dp(sentence.size() + 1, 0);
        for (int i = 1; i < dp.size(); ++i) {
            dp[i] = dp[i - 1] + 1;
            for (int j = i; j >= 1; --j) {
                if (hash_set.count(sentence.substr(j - 1, i - j + 1))) {
                    dp[i] = min(dp[i], dp[j-1]);
                }
            }
        }
        return dp[sentence.size()];
    }
};

