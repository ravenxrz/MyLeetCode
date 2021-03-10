
/**
 *
 * 输入：beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
    输出：5
    解释：一个最短转换序列是 "hit" -> "hot" -> "dot" -> "dog" -> "cog", 返回它的长度 5。
 *
 *
 */


#include <string>
#include <vector>
#include <unordered_map>
#include <queue>
#include <iostream>

using namespace std;


/**
 * 单dfs解法
 */
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        unordered_map<string, bool> hash_map;
        // add all words into hash_set
        for (const auto &word : wordList) {
            hash_map.insert({word, false});
        }
        // check endWord in hash_set or not
        if (hash_map.count(endWord) == 0) return 0;
        // ok, everything prepared, use bfs to calc dist
        int next_level = 0;
        int cur_level = 0;
        int dist = 1;
        queue<string> qe;
        // bfs
        hash_map[beginWord] = true;
        qe.push(beginWord);
        cur_level = 1;
        while (!qe.empty()) {
            auto node = qe.front();
            qe.pop();
            cur_level--;
            if (node == endWord) return dist;
            // push next level nodes
            auto nodes = getNextLevelNodes(node, hash_map);
            next_level += nodes.size();
            for (int i = 0; i < nodes.size(); ++i) {
                qe.push(nodes[i]);
            }
            if (cur_level == 0) {
                cur_level = next_level;
                next_level = 0;
                dist++;
            }
        }
        return 0;
    }

private:
    vector<string> getNextLevelNodes(string base, unordered_map<string, bool> &hash_map)
    {
        const int len = base.length();
        vector<string> nodes;
        for (int i = 0; i < len; i++) {
            int save = base[i];
            for (int c = 'a'; c <= 'z'; c++) {
                // set
                base[i] = c;
                if (hash_map.count(base) == 0) continue;
                // else
                if (hash_map[base]) continue;
                // now we can get this node
                nodes.push_back(base);
                hash_map[base] = true;
            }
            base[i] = save;
        }
        return nodes;
    }
};





int main()
{
    Solution sol;
    vector<string> wordList{"hot", "dot", "dog", "lot", "log", "cog"};
    cout << sol.ladderLength("hit", "cog", wordList) << '\n';
    return 0;
}
