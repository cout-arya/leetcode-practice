class Solution {
private:
    bool isSafe(int r, int c, vector<string>& board, int n) {
        int r1 = r;
        int c1 = c;
        while (r >= 0 && c >= 0) {
            if (board[r][c] == 'Q')
                return false;
            r--;
            c--;
        }
        r = r1;
        c = c1;
        while (c >= 0) {
            if (board[r][c] == 'Q')
                return false;
            c--;
        }
        r = r1;
        c = c1;
        while (r < n && c >= 0) {
            if (board[r][c] == 'Q')
                return false;
            r++;
            c--;
        }
        return true;
    }

public:
    void solve(int col, vector<string>& board, int& count, int n) {
        if (col == n) {
            count++;
            return;
        }
        for (int row = 0; row < n; row++) {
            if (isSafe(row, col, board, n)) {
                board[row][col] = 'Q';
                solve(col + 1, board, count, n);
                board[row][col] = '.';
            }
        }
    }
    int totalNQueens(int n) {
        int count = 0;
        vector<string> board(n, string(n, '.'));
        solve(0, board, count, n);
        return count;
    }
};