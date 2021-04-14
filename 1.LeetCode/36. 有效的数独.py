from typing import List


class Solution:
    def isValidSudoku(self, board: List[List[str]]) -> bool:
        # decalre three map to save row, column and 9x9 boxes status respectively
        row_ = set()
        column_ = set()
        boxes_ = set()  # boxes_ id range [0-8], from top to bottom and left to right

        for i in range(len(board)):
            for j in range(len(board[0])):
                if board[i][j] == '.':
                    continue
                # row check
                if not i in row_:
                    # optimize: use bitmap rather than a list to save space
                    visit = [False for _ in range(10)]
                    for k in range(0, 9):
                        if board[i][k] == '.':
                            continue
                        if visit[int(board[i][k])]:
                            return False
                        visit[int(board[i][k])] = True
                    row_.add(i)
                # col check
                if not j in column_:
                    visit = [False for _ in range(10)]
                    for k in range(0, 9):
                        if board[k][j] == '.':
                            continue
                        if visit[int(board[k][j])]:
                            return False
                        visit[int(board[k][j])] = True
                    column_.add(j)

                # boxes check
                if not i // 3 * 3 + j // 3 in boxes_:
                    visit = [False for _ in range(10)]
                    for k in range(0, 9):
                        row_delta = k // 3
                        col_delta = k % 3
                        if board[row_delta + i // 3 * 3][col_delta + j // 3 * 3] == '.':
                            continue
                        if visit[int(board[row_delta + i // 3 * 3][col_delta + j // 3 * 3])]:
                            return False
                        visit[int(board[row_delta + i // 3 * 3][col_delta + j // 3 * 3])] = True
                    boxes_.add(i // 3 * 3 + j // 3)

        return True


if __name__ == '__main__':
    sol = Solution()
    board = [
          ["5", "3", ".", ".", "7", ".", ".", ".", "."]
        , ["6", ".", ".", "1", "9", "5", ".", ".", "."]
        , [".", "9", "8", ".", ".", ".", ".", "6", "."]
        , ["8", ".", ".", ".", "6", ".", ".", ".", "3"]
        , ["4", ".", ".", "8", ".", "3", ".", ".", "1"]
        , ["7", ".", ".", ".", "2", ".", ".", ".", "6"]
        , [".", "6", ".", ".", ".", ".", "2", "8", "."]
        , [".", ".", ".", "4", "1", "9", ".", ".", "5"]
        , [".", ".", ".", ".", "8", ".", ".", "7", "9"]]
    print(sol.isValidSudoku(board))
    board = [["8", "3", ".", ".", "7", ".", ".", ".", "."]
        , ["6", ".", ".", "1", "9", "5", ".", ".", "."]
        , [".", "9", "8", ".", ".", ".", ".", "6", "."]
        , ["8", ".", ".", ".", "6", ".", ".", ".", "3"]
        , ["4", ".", ".", "8", ".", "3", ".", ".", "1"]
        , ["7", ".", ".", ".", "2", ".", ".", ".", "6"]
        , [".", "6", ".", ".", ".", ".", "2", "8", "."]
        , [".", ".", ".", "4", "1", "9", ".", ".", "5"]
        , [".", ".", ".", ".", "8", ".", ".", "7", "9"]]
    print(sol.isValidSudoku(board))
    board = [[".", ".", ".", ".", "5", ".", ".", "1", "."],
             [".", "4", ".", "3", ".", ".", ".", ".", "."],
             [".", ".", ".", ".", ".", "3", ".", ".", "1"],
             ["8", ".", ".", ".", ".", ".", ".", "2", "."],
             [".", ".", "2", ".", "7", ".", ".", ".", "."],
             [".", "1", "5", ".", ".", ".", ".", ".", "."],
             [".", ".", ".", ".", ".", "2", ".", ".", "."],
             [".", "2", ".", "9", ".", ".", ".", ".", "."],
             [".", ".", "4", ".", ".", ".", ".", ".", "."]]
    print(sol.isValidSudoku(board))
