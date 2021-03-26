#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string longestWord(vector<string> &words)
    {
        sort(words.begin(), words.end(), [](const string &lhs, const string &rhs) {
            if (lhs.length() == rhs.length()) {
                for (int i = 0; i < lhs.length(); ++i) {
                    if (lhs[i] == rhs[i]) continue;
                    return lhs[i] > rhs[i];
                }
                // program will not be here at normal case
                return true;
            }
            return lhs.length() < rhs.length();
        });
        for (int i = words.size() - 1; i >= 0; --i) {
            if (doFind(words, words[i], 0, i)) {
                return words[i];
            }
        }
        return "";
    }
    
    bool doFind(const vector<string> &words, const string &word, int start_pos, int word_idx)
    {
        if (start_pos >= word.size()) return true;
        
        const string &sub_str = word.substr(start_pos);
        for (int i = 0; i < word_idx; ++i) {
            if (compare(sub_str, words[i])) {
                bool ret = doFind(words, word, start_pos + words[i].size(), word_idx);
                if (ret) return true;
            }
        }
        return false;
    }
    
    bool compare(const string &str1, const string &str1_substr)
    {
        int i = 0, j = 0;
        while (i < str1.size() && j < str1_substr.size()) {
            if (str1[i++] != str1_substr[j++]) return false;
        }
        return j == str1_substr.size();
    }
};

int main()
{
    Solution sol;
    /**
     * []
     */
    vector<string> str = {"pg", "ptgt", "tgpppttg", "tptttgg", "pgttggtpt", "t", "ptg", "ppgp", "g", "ptgpptpgg"};
    cout << sol.longestWord(str) << endl;
    
    return 0;
}
