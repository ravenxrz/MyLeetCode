#include <vector>

using namespace std;

class Solution {
public:
    void solve(vector<vector<char>> &board)
    {
        const int m = board.size();
        if (m == 0) return;
        const int n = board[0].size();
        if (n == 0) return;
        // 从边缘触发
        for (int j = 0; j < n; j++) {
            // 第一行
            // 最后一行
            dfs(board, 0, j);
            dfs(board, m - 1, j);
        }
        for (int i = 1; i < m - 1; i++) {
            // 第一列和最后一列
            dfs(board, i, 0);
            dfs(board, i, n - 1);
        }
        // 设置0 --> X
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O') board[i][j] = 'X';
            }
        }
        // 设置 "-" --> 0
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == '-') board[i][j] = 'O';
            }
        }
    }

private:
    void dfs(vector<vector<char>> &board, int i, int j)
    {
        if (i < 0 || i >= board.size() ||
            j < 0 || j >= board[0].size()) {
            return;
        }
        if (board[i][j] != 'O') return;
        board[i][j] = '-';
        // 上
        dfs(board, i - 1, j);
        // 下
        dfs(board, i + 1, j);
        // 左
        dfs(board, i, j - 1);
        // 右
        dfs(board, i, j + 1);
    }
};

class Solution {
private:
    class UF {
    public:
        UF(int size) : count(size)
        {
            parent.resize(size);
            // init
            for (int i = 0; i < size; ++i) {
                parent[i] = i;
            }
        }
        
        int find_parent(int x)
        {
            assert(x < parent.size() && x >= 0);
            int root = x;
            while (parent[root] != root) {
                root = parent[root];
            }
            // 路径压缩
            while (parent[x] != root) {
                int save_p = parent[x];
                parent[x] = root;
                x = save_p;
            }
            return root;
        }
        
        bool is_same_set(int x, int y)
        {
            int parent_x = find_parent(x);
            int parent_y = find_parent(y);
            return parent_x == parent_y;
        }
        
        void merge(int x, int y)
        {
            int parent_x = find_parent(x);
            int parent_y = find_parent(y);
            if (parent_x == parent_y) return;
            parent[parent_y] = parent_x;
            --count;
        }
        
        int getCount() const
        {
            return count;
        }
    
    private:
        std::vector<int> parent;
        int count;
    };

public:
    void solve(vector<vector<char>> &board)
    {
        const int m = board.size();
        const int n = board[0].size();
        UF uf(m * n + 1);
        int dummy = m * n;
        // 扫描边界，将边界上的 'O' 合并到一个集合和中
        // 首行和尾行
        for (int j = 0; j < n; ++j) {
            if (board[0][j] == 'O') {
                uf.merge(dummy, dim2todim1(0, j, n));
            }
            if (board[m - 1][j] == 'O') {
                uf.merge(dummy, dim2todim1(m - 1, j, n));
            }
        }
        // 首列和尾列
        for (int i = 0; i < m; ++i) {
            if (board[i][0] == 'O') {
                uf.merge(dummy, dim2todim1(i, 0, n));
            }
            if (board[i][n - 1] == 'O') {
                uf.merge(dummy, dim2todim1(i, n - 1, n));
            }
        }
        // 扫描全盘，合并相连
        vector<vector<int>> direction = {
                {1,  0},      //  down
                {-1, 0},        // up
                {0,  1},        // right
                {0,  -1}        // left
        };
        for (int i = 1; i < m - 1; ++i) {
            for (int j = 1; j < n - 1; ++j) {
                if (board[i][j] == 'O') {
                    // 从i，j点向四周扫描
                    for (int k = 0; k < direction.size(); ++k) {
                        int x = i + direction[k][0];
                        int y = j + direction[k][1];
                        if (board[x][y] == 'O') {
                            uf.merge(dim2todim1(i, j, n), dim2todim1(x, y, n));
                        }
                    }
                }
            }
        }
        // 最后将不和dummy为一组的设置为'X'
        for (int i = 1; i < m - 1; ++i) {
            for (int j = 1; j < n - 1; ++j) {
                if (board[i][j] == 'O' && !uf.is_same_set(dim2todim1(i, j, n), dummy)) {
                    board[i][j] = 'X';
                }
            }
        }
    }
    
    int dim2todim1(int x, int y, int elem_per_col)
    {
        return x * elem_per_col + y;
    }
};

int main()
{
    vector<vector<char>> board =
            {{'O', 'X', 'X', 'O', 'X'},
             {'X', 'O', 'O', 'X', 'O'},
             {'X', 'O', 'X', 'O', 'X'},
             {'O', 'X', 'O', 'O', 'O'},
             {'X', 'X', 'O', 'X', 'O'}};
    Solution sol;
    sol.solve(board);
    return 0;
}



