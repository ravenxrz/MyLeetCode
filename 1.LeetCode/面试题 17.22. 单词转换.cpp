#include <bits/stdc++.h>

using namespace std;


class Solution {
    void push_next_level(string &cur, unordered_set<string> &words, queue<string> &qe,
                         unordered_map<string, string> &word_map, unordered_set<string> &visit)
    {
        string old = cur;
        for (int i = 0; i < cur.size(); ++i) {
            char c = cur[i];
            for (int d = 'a'; d <= 'z'; ++d) {
                cur[i] = d;
                if (words.count(cur) && visit.count(cur) == 0) {
                    visit.insert(cur);
                    word_map[cur] = old;
                    qe.push(cur);
                }
            }
            cur[i] = c;
        }
    }

public:
    vector<string> findLadders(string beginWord, string endWord, vector<string> &wordList)
    {
        queue<string> qe;
        unordered_map<string, string> word_map;
        unordered_set<string> visit;
        unordered_set<string> words;
        
        // init
        qe.push(beginWord);
        visit.insert(beginWord);
        word_map[beginWord] = beginWord;
        for (auto &str : wordList) {
            words.insert(str);
        }
        
        // bfs
        while (!qe.empty()) {
            int sz = qe.size();
            for (int i = 0; i < sz; ++i) {
                auto cur_word = qe.front();
                qe.pop();
                
                if (cur_word == endWord) break;
                
                // push next level
                push_next_level(cur_word, words, qe, word_map,visit);
            }
        }
        
        // get ans
        if (word_map.count(endWord) == 0) return {};
        
        vector<string> ans;
        auto word = endWord;
        ans.push_back(word);
        while (word != word_map[word]) {
            word = word_map[word];
            ans.push_back(word);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};


int main()
{
    Solution sol;
    vector<string> wordList = {"hot", "dot", "dog", "lot", "log", "cog"};
    sol.findLadders("hit", "cog", wordList);
    return 0;
}
