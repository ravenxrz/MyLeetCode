//
// Created by Raven on 2021/3/22.
//

class Solution {
public:
    vector<int> findSquare(vector <vector<int>> &matrix)
    {
        int start_row = -1, start_col = -1, max_len = 0;
        vector <vector<int>> mark(matrix.size(), vector<int>(matrix.size(), 0));
        
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix.size(); ++j) {
                if (matrix[i][j] == 0 && mark[i][j] == 0) {
                    mark[i][j] = 1;
                    int try_row = i + 1, try_col = j + 1;
                    // 尝试扩大matrix
                    while (try_row < matrix.size() && try_col < matrix.size() && matrix[try_row][try_col] == 0) {
                        //  臂长
                        int hand_len = mark[try_row - 1][try_col - 1];
                        bool largerMatrix = true;
                        for (int delta = 1;
                             delta <= hand_len && try_row - delta >= 0 && try_col - delta >= 0; delta++) {
                            if (matrix[try_row][try_col - delta] != 0 ||
                                matrix[try_row - delta][try_col] != 0) {
                                largerMatrix = false;
                                break;
                            }
                        }
                        if (largerMatrix) {
                            mark[try_row][try_col] = mark[try_row - 1][try_col - 1] + 1;
                            ++try_row;
                            ++try_col;
                        } else {
                            break;
                        }
                    }
                    --try_row;
                    --try_col;
                    // 更新最大矩阵
                    if (try_row >= 0 && try_col >= 0 && mark[try_row][try_col] != -1) {
                        if (max_len < mark[try_row][try_col]) {
                            max_len = mark[try_row][try_col];
                            start_row = try_row - max_len + 1;
                            start_col = try_col - max_len + 1;
                        }
                    }
                }
            }
        }
        if (max_len == 0) return {};
        return {start_row, start_col, max_len};
    }
};

