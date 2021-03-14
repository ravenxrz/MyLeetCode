//
// Created by Raven on 2021/3/13.
//
#include <bits/stdc++.h>

using namespace std;


class Solution {
private:
public:
    int openLock(vector<string> &deadends, string target)
    {
        queue<string> qe;
        int steps = 0;
        hashset.clear();
        
        // insert deadends
        for (const auto &str : deadends) {
            hashset.insert(str);
        }
        
        if (hashset.count("0000") == 0) {
            qe.push("0000");
        }
        
        while (!qe.empty()) {
            int sz = qe.size();
            
            for (int i = 0; i < sz; i++) {
                auto cur = qe.front();
                qe.pop();
                if (cur == target) return steps;
                // push next level
                for (int i = 0; i < 4; i++) {
                    int save = cur[i];
                    // 顺时针
                    if (cur[i] == '9') cur[i] = '0';
                    else cur[i] += 1;
                    if (hashset.count(cur) == 0) {
                        hashset.insert(cur);
                        qe.push(cur);
                    }
                    // 逆时针
                    cur[i] = save;
                    if (cur[i] == '0') cur[i] = '9';
                    else cur[i] -= 1;
                    if (hashset.count(cur) == 0) {
                        hashset.insert(cur);
                        qe.push(cur);
                    }
                    cur[i] = save;
                }
            }
            
            steps++;
        }
        return -1;
    }

private:
    unordered_set<string> hashset;
};

int main()
{
    Solution sol;
    vector<string> deadends{"0201", "0101", "0102", "1212", "2002"};
    cout << sol.openLock(deadends, "0202") << '\n';
    return 0;
}

class Solution {
private:
public:
    int openLock(vector<string> &deadends, string target)
    {
        unordered_set<string> dead;
        for (const auto &str : deadends) dead.insert(str);
        
        unordered_set<string> q1;
        unordered_set<string> q2;
        unordered_set<string> visit1;
        unordered_set<string> visit2;
        
        int step = 0;
        q1.insert("0000");
        q2.insert(target);
        visit1.insert("0000");
        visit2.insert(target);
        
        while (!q1.empty() && !q2.empty()) {
            unordered_set<string> tmp;
            if (q1.size() > q2.size()) {
                q1.swap(q2);
                visit1.swap(visit2);
            }
            
            for (auto cur : q1) {
                if (dead.count(cur)) continue;
                if (q2.count(cur)) return step;
                
                /* insert */
                for (int i = 0; i < 4; i++) {
                    int save = cur[i];
                    // 顺时针
                    if (cur[i] == '9') cur[i] = '0';
                    else cur[i] += 1;
                    if (visit1.count(cur) == 0) {
                        visit1.insert(cur);
                        tmp.insert(cur);
                    }
                    // 逆时针
                    cur[i] = save;
                    if (cur[i] == '0') cur[i] = '9';
                    else cur[i] -= 1;
                    if (visit1.count(cur) == 0) {
                        visit1.insert(cur);
                        tmp.insert(cur);
                    }
                    cur[i] = save;
                }
            }
            step++;
            q1.swap(q2);
            q2.swap(tmp);
            visit1.swap(visit2);
        }
        return -1;
    }
    
};

int main()
{
    Solution sol;
    vector<string> deadends{"0201", "0101", "0102", "1212", "2002"};
    cout << sol.openLock(deadends, "0202") << '\n';
    return 0;
}
