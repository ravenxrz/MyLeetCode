#include <bits/stdc++.h>
using namespace std;

/**
 * @brief 超时做法
 *
 */
// class Solution {
//    private:
//     bool anyMatch(const string& w1, const string& w2) {
//         static unordered_set<char> tmp;
//         tmp.clear();
//         for (char c : w1) {
//             tmp.insert(c);
//         }
//         for (char c : w2) {
//             if (tmp.count(c)) {
//                 return true;
//             }
//         }
//         return false;
//     }

//    public:
//     int maxProduct(vector<string>& words) {
//         sort(words.begin(), words.end(),
//              [](const string& w1, const string& w2) {
//                  return w1.length() < w2.length();
//              });
//         size_t max_len = 0;
//         for (int start = 0; start < words.size() - 1; start++) {
//             int i = start;
//             int j = words.size() - 1;
//             while (i < j) {
//                 if (!anyMatch(words[i], words[j])) {
//                     max_len =
//                         max(max_len, words[i].length() * words[j].length());
//                     break;
//                 }
//                 j--;
//             }
//         }

//         return max_len;
//     }
// };

class Solution {
   public:
    int maxProduct(vector<string>& words) {
        vector<int> bitmaps(words.size(), 0);
        for (int i = 0; i < words.size(); i++) {
            for (char c : words[i]) {
                bitmaps[i] |= 1 << (c - 'a');
            }
        }

        size_t max_len = 0;
        for (int i = 0; i < words.size() - 1; i++) {
            for (int j = i + 1; j < words.size(); j++) {
                if ((bitmaps[i] & bitmaps[j]) == 0) {
                    max_len = max(max_len, words[i].size() * words[j].size());
                }
            }
        }
        return max_len;
    }
};

int main() {
    Solution sol;
    {
        vector<string> strs = {"abcw", "baz", "foo", "bar", "fxyz", "abcdef"};
        cout << sol.maxProduct(strs) << endl;
    }

    return 0;
}