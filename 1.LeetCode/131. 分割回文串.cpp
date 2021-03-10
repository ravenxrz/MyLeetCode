class Solution {
public:
    vector<vector<string>> partition(string s)
    {
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
        
        // 计算dp
        for (int delta = 0; delta < s.size(); delta++) {
            for (int start = 0; start + delta < s.size(); start++) {
                if (delta == 0) {
                    dp[start][start] = true;
                } else if (delta == 1) {
                    dp[start][start + 1] = s[start] == s[start + 1];
                } else {
                    int left = start;
                    int right = start + delta;
                    dp[left][right] = dp[left + 1][right - 1] && (s[left] == s[right]);
                }
            }
        }
        
        // 通过dfs得到计算结果
        ans.clear();
        vector<string> tmp;
        dfs(s, dp, tmp, 0);
        return ans;
    }

private:
    void dfs(const string &s, const vector<vector<bool>> &dp, vector<string> &tmp, int idx)
    {
        if (idx >= s.size()) {
            ans.push_back(tmp);
            return;
        }
        
        // dfs
        for (int i = idx; i < s.size(); i++) {
            if (dp[idx][i]) {
                tmp.push_back(s.substr(idx, i - idx + 1));
                dfs(s, dp, tmp, i+1);
                tmp.pop_back();
            }
        }
    }

private:
    vector<vector<string>> ans;
};
