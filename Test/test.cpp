/*
 * @lc app=leetcode.cn id=127 lang=cpp
 *
 * [127] 单词接龙
 */
#include <queue>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>

using namespace std;

// @lc code=start
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string> &wordList)
    {
        sort(wordList.begin(), wordList.end());
        auto iter = binary_find(wordList.begin(), wordList.end(), endWord);
        if (iter == wordList.end()) return 0;
        
        vector<int> visit1;
        queue<int> qe1;
        const vector<int> &conn = findConnectStrs(beginWord, visit1, wordList);
        for (auto val : conn) {
            visit1.push_back(val);
            qe1.push(val);
        }
        if(find(visit1.begin(),visit1.end(),iter-wordList.begin()) != visit1.end()){
            return 2;
        }
        
        vector<int> visit2;
        queue<int> qe2;
        qe2.push(iter - wordList.begin());
        visit2.push_back(iter - wordList.begin());
        
        int count = 1;
        
        while (!qe1.empty() && !qe2.empty()) {
            const int size1 = qe1.size();
            const int size2 = qe2.size();
            count++;
            // 从队列短的那一端开始遍历
            if (size1 <= size2) {
                for (int i = 0; i < size1; i++) {
                    const string &cur_str = wordList.at(qe1.front());
                    qe1.pop();
                    // push connected nodes
                    vector<int> conn = findConnectStrs(cur_str, visit1, wordList);
                    for (int i = 0; i < conn.size(); i++) {
                        if (find(visit2.begin(), visit2.end(), conn[i]) != visit2.end()) {
                            return count + 1;
                        }
                        qe1.push(conn[i]);
                    }
                }
            } else {
                for (int i = 0; i < size2; i++) {
                    const string &cur_str = wordList.at(qe2.front());
                    qe2.pop();
                    vector<int> conn = findConnectStrs(cur_str, visit2, wordList);
                    for (int i = 0; i < conn.size(); i++) {
                        if (find(visit1.begin(), visit1.end(), conn[i]) != visit1.end()) {
                            return count + 1;
                        }
                        qe2.push(conn[i]);
                    }
                }
            }
        }
        
        return 0;
    }

private:
    vector<int> findConnectStrs(string base, vector<int> &visit, vector<string> &wordList)
    {
        vector<int> tmp;
        for (int i = 0; i < base.size(); i++) {
            char save_c = base.at(i);
            for (char c = 'a'; c <= 'z'; c++) {
                base[i] = c;
                auto iter = binary_find(wordList.begin(), wordList.end(), base);
                if (iter != wordList.end()) {
                    int idx = iter - wordList.begin();
                    if (find(visit.begin(), visit.end(), idx) == visit.end()) {
                        visit.push_back(idx);
                        tmp.push_back(idx);
                    }
                }
            }
            base[i] = save_c;
        }
        return tmp;
    }
    
    template<class Iter, class T>
    Iter binary_find(Iter begin, Iter end, T val)
    {
        // Finds the lower bound in at most log(last - first) + 1 comparisons
        Iter i = std::lower_bound(begin, end, val);
        
        if (i != end && !(val < *i))
            return i; // found
        else
            return end; // not found
    }
};

// @lc code=end

int main()
{
    Solution sol;
    vector<string> wordList = {"hot", "dot", "dog"};
    cout << sol.ladderLength("hot", "dog", wordList);
    return 0;
}

