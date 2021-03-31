//
// Created by Raven on 2021/3/31.
//

class Solution {
public:
    vector<int> bestLine(vector <vector<int>> &points)
    {
        vector <vector<int>> record(points.size(), vector<int>(points.size(), 0));
        for (int i = 0; i < points.size(); ++i) {
            for (int j = i + 1; j < points.size(); ++j) {
                if (record[i][j]) continue;
                vector<int> tmp_same_line = {i, j};
                for (int k = j + 1; k < points.size(); ++k) {
                    if (checkInTheSameLine(points[i], points[j], points[k])) {
                        tmp_same_line.push_back(k);
                    }
                }
                // update record table
                updateTable(record, tmp_same_line);
            }
        }
        // find max value
        int max_value = 0;
        int start_point = -1;
        int end_point = -1;
        for (int i = 0; i < record.size(); ++i) {
            for (int j = i + 1; j < record[0].size(); ++j) {
                if (max_value < record[i][j]) {
                    max_value = record[i][j];
                    start_point = i;
                    end_point = j;
                }
            }
        }
        return {start_point, end_point};
    }
    
    void updateTable(vector <vector<int>> &record, vector<int> &tmp_same_line)
    {
        const int sz = tmp_same_line.size();
        for (int i = 0; i < sz; ++i) {
            for (int j = i + 1; j < sz; ++j) {
                int x = tmp_same_line[i];
                int y = tmp_same_line[j];
                record[x][y] = sz;
            }
        }
    }
    
    bool checkInTheSameLine(vector<int> &p0, vector<int> &p1, vector<int> &p2)
    {
        return (long long) (p1[1] - p0[1]) * (p2[0] - p0[0]) == (long long) (p2[1] - p0[1]) * (p1[0] - p0[0]);
    }
};

