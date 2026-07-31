class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char> row[9];
        unordered_set<char> col[9];
        unordered_set<char> boxes[9];

        for (int r = 0; r < 9; ++r) {
            for (int c = 0; c < 9; ++c) {
                if (board[r][c] == '.') {
                    continue;
                }
                char val = board[r][c];
                int boxInd = (r / 3) * 3 + (c / 3);

                if (row[r].count(val) || col[c].count(val) ||
                    boxes[boxInd].count(val)) {
                    return false;
                }
                row[r].insert(val);
                col[c].insert(val);
                boxes[boxInd].insert(val);
            }
        }
        return true;
    }
};