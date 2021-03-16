//
// Created by Raven on 2021/3/16.
//

class Solution {
public:
    int slidingPuzzle(vector <vector<int>> &board)
    {
        int steps = 0;
        unordered_set <string> qe1;
        unordered_set <string> qe2;
        unordered_set <string> visit1;
        unordered_set <string> visit2;
        
        string start = convert2str(board);
        string target = "123450";
        qe1.insert(start);
        qe2.insert(target);
        visit1.insert(start);
        visit2.insert(target);
        
        vector <vector<int>> neighbor_idx = {
                {1, 3},
                {0, 2, 4},
                {1, 5},
                {0, 4},
                {1, 3, 5},
                {2, 4}
        };
        
        while (!qe1.empty() && !qe2.empty()) {
            if (qe1.size() > qe2.size()) {
                qe1.swap(qe2);
                visit1.swap(visit2);
            }
            unordered_set <string> tmp;
            
            for (auto cur : qe1) {
                if (qe2.count(cur) != 0) return steps;
                
                // push next level
                // find zero
                int k = 0;
                for (; cur[k] != '0'; ++k);
                for (auto n_idx: neighbor_idx[k]) {
                    swap(cur[k], cur[n_idx]);
                    if (visit1.count(cur) == 0) {
                        visit1.insert(cur);
                        tmp.insert(cur);
                    }
                    swap(cur[k], cur[n_idx]);
                }
                
            }
            
            qe1.swap(qe2);
            qe2.swap(tmp);
            steps++;
        }
        return -1;
    }
    
    string convert2str(const vector <vector<int>> &board)
    {
        static char buf[8];
        sprintf(buf, "%d%d%d%d%d%d", board[0][0], board[0][1], board[0][2], board[1][0], board[1][1], board[1][2]);
        return buf;
    }
};

