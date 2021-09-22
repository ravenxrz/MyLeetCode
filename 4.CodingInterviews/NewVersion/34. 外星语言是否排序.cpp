#include "leetcode_base.h"

class Solution {
   public:
    bool isAlienSorted(vector<string>& words, string order) {
        // init table
        int order_table[26];
        for (int i = 0; i < order.size(); i++) {
            order_table[order[i] - 'a'] = i;
        }

        for (int i = 0; i < words.size() - 1; i++) {
            for (int j = i + 1; j < words.size(); j++) {
                if (!less_or_equal(order_table, words[i], 0, words[j], 0)) {
                    return false;
                }
            }
        }
        return true;
    }

   private:
    bool less_or_equal(int* order_table,
                       const string& word1,
                       int i,
                       const string& word2,
                       int j) {
        while (i < word1.size() && j < word2.size() && word1[i] == word2[j]) {
            i++;
            j++;
        }
        if (i == word1.size()) {
            return true;
        } else if (i != word1.size() && j == word2.size()) {
            return false;
        } else if (i != word1.size() && j != word2.size() &&
                   word1[i] != word2[j]) {
            return (order_table[word1[i] - 'a'] < order_table[word2[i] - 'a']);
        }
        /* program will no be here */
        return false;
    }
};

int main() {
    Solution sol;
    vector<string> words = {"hello", "leetcode"};
    string order = "hlabcdefgijkmnopqrstuvwxyz";
    cout << sol.isAlienSorted(words, order) << endl;
    return 0;
}