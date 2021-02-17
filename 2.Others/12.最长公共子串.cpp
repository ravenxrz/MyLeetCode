class Solution {
public:
    /**
     * longest common substring
     * @param str1 string字符串 the string
     * @param str2 string字符串 the string
     * @return string字符串
     */
    string LCS(string str1, string str2)
    {
        // write code here
        const int len1 = str1.length();
        const int len2 = str2.length();
        vector<vector<int>> dp(len1 + 1, vector<int>(len2 + 1, 0));
        
        // init
        int max_len = 0;
        int max_i = 0, max_j = 0;
        for (int i = 1; i <= len1; i++) {
            for (int j = 1; j <= len2; j++) {
                if (str1[i - 1] == str2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    if (max_len < dp[i][j]) {
                        max_len = dp[i][j];
                        max_i = i - 1;
                        max_j = j - 1;
                    }
                }
            }
        }
        if (max_len == 0) return "-1";
        // trace back
        string ans;
        while (max_i >= 0 && max_j >= 0 && str1[max_i] == str2[max_j]) {
            ans.insert(0, 1, str1[max_i]);
            max_i--;
            max_j--;
        }
        return ans;
    }
};
