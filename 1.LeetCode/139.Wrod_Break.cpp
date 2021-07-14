
#include "leetcode_base.h"

class Solution {
public:
  bool wordBreak(const string &s, const vector<string> &wordDict) {
    vector<bool> dp(s.size(), false);
    // Init: find a word which is the shortest leading substring of s
    int start_len = s.size() + 1;
    for (const string &word : wordDict) {
      if (isLeadingSubString(s, word)) {
        start_len = min(start_len, static_cast<int>(word.size()));
      }
    }
    if (start_len ==
        s.size() + 1) // There is no word that matchs substring of s
      return false;
    dp[start_len - 1] = true;

    // Calculate the remaining characters
    for (int i = start_len; i < s.size(); i++) {
      // First check the whole word
      if (hasWord(wordDict, s.substr(0, i + 1))) {
        dp[i] = true;
        continue;
      }
      // Else, use dp array
      for (int j = i - 1; j >= 0; j--) {
        if (dp[j] && hasWord(wordDict, s.substr(j + 1, i - j))) {
          dp[i] = true;
          break;
        }
      }
    }
    return dp[s.size() - 1];
  }

private:
  bool hasWord(const vector<string> &dict, const string &s) {
    for (const string &word : dict) {
      if (word == s) {
        return true;
      }
    }
    return false;
  }

  bool isLeadingSubString(const string &s1, const string s2) {
    assert(!s1.empty());
    assert(!s2.empty());

    int i = 0;
    int j = 0;
    while (i < s1.size() && j < s2.size()) {
      if (s1[i] != s2[j])
        return false;
      i++;
      j++;
    }

    return i <= s1.size() && j == s2.size();
  }
};

int main() {
  Solution sol;

  cout << sol.wordBreak("leetcode", {"leet", "code"}) << endl;
  cout << sol.wordBreak("applepenapple", {"apple", "pen"}) << endl;
  cout << sol.wordBreak("catsandog", {"cats", "dog", "sand", "and", "cat"})
       << endl;
  cout << sol.wordBreak("cat", {"ca", "at"}) << endl;

  return 0;
}
