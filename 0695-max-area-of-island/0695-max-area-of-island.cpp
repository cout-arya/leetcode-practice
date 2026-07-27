class Solution {
public:
    int dfs(int r, int c, vector<vector<int>>& grid, vector<vector<int>>& vis,
            int drow[], int dcol[]) {
        int m = grid.size();
        int n = grid[0].size();
        vis[r][c] = 1;
        int cnt = 1;
        for (int i = 0; i < 4; i++) {
            int nrow = r + drow[i];
            int ncol = c + dcol[i];
            int count = 0;
            if (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n &&
                !vis[nrow][ncol] && grid[nrow][ncol] == 1) {
                cnt += dfs(nrow, ncol, grid, vis, drow, dcol);
            }
        }
        return cnt;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int ans = 0;
        vector<vector<int>> vis(m, vector<int>(n, 0));
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1 && !vis[i][j]) {
                    ans = max(ans, dfs(i, j, grid, vis, drow, dcol));
                }
            }
        }
        return ans;
    }
};