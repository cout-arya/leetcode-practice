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
    void solve(int col, vector<string>& board, vector<vector<string>>& res,
               int n) {
        if (col == n) {
            res.push_back(board);
            return;
        }
        for (int row = 0; row < n; row++) {
            if (isSafe(row, col, board, n)) {
                board[row][col] = 'Q';
                solve(col + 1, board, res, n);
                board[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> board(n);
        string s(n, '.');
        for (int i = 0; i < n; i++) {
            board[i] = s;
        }
        solve(0, board, res, n);
        return res;
    }
};