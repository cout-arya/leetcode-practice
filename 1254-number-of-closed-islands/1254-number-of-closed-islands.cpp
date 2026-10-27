class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n, false));
        const int dir[5] = {-1, 0, 1, 0, -1};
        int ans = 0;

        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {
                if (grid[r][c] != 0 || visited[r][c]) {
                    continue;
                }
                queue<pair<int, int>> q;
                q.push({r, c});
                visited[r][c] = true;
                bool closed = true;

                while (!q.empty()) {
                    auto [row, col] = q.front();
                    q.pop();

                    if(row==0||row==m-1||col==0||col==n-1){
                        closed=false;
                    }
            for (int d = 0; d < 4; d++) {
                int nr = row + dir[d];
                int nc = col + dir[d + 1];

                if (nr >= 0 && nr < m && nc >= 0 && nc < n &&
                    grid[nr][nc] == 0 && !visited[nr][nc]) {
                    visited[nr][nc] = true;
                    q.push({nr, nc});
                }
            }
        }
        if (closed) {
            ans++;
        }
    }
} return ans;
}
}
;