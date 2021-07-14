#include "leetcode_base.h"

class Solution {
   public:
    bool wordBreak(string s, const vector<string>& wordDict) {
        return check(s, 0, wordDict);
    }

   private:
    bool check(const string& s, int start, const vector<string>& wordDict) {
        if (start >= s.size())
            return true;

        for (const string& word : wordDict) {
            if (!isSubStr(s, start, word))
                continue;
            bool ret = check(s, start + word.size(), wordDict);
            if (ret)
                return true;
        }
        return false;
    }

    bool isSubStr(const string& s, int start, const string& sub) {
        int i = start;
        int j = 0;
        while (i < s.size() && j < sub.size()) {
            if (s[i] != sub[j])
                return false;
            i++;
            j++;
        }
        return i <= s.size() && j == sub.size();
    }
};

int main() {
    Solution sol;
    {
        cout << sol.wordBreak("leetcode", {"leet", "code"}) << endl;
        cout << sol.wordBreak("applepenapple", {"apple", "pen"}) << endl;
        cout << sol.wordBreak("catsandog",
                              {"cats", "dog", "sand", "and", "cat"})
             << endl;
    }

    return 0;
}