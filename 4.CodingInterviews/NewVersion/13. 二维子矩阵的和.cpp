#include <bits/stdc++.h>
using namespace std;

class NumMatrix {
   public:
    NumMatrix(vector<vector<int>>& matrix) {
        col_sums.resize(matrix.size());
        for (int i = 0; i < matrix.size(); i++) {
            int sum = 0;
            for (int j = 0; j < matrix[i].size(); j++) {
                sum += matrix[i][j];
                col_sums[i].push_back(sum);
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        int ans = 0;
        for (int i = row1; i <= row2; i++) {
            ans += col_sums[i][col2] - (col1 == 0 ? 0 : col_sums[i][col1 - 1]);
        }
		return ans;
    }

   private:
    vector<vector<int>> col_sums;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */

int main() {
	// NumMatrix nm();
    return 0;
}