class Solution {
public:
    int numSquares(int n) {
        vector<int> sq;
        for (int i = 1; i * i <= n; i++) {
            sq.push_back(i * i);
        }
        int len = sq.size();
        vector<vector<int>> dp(len, vector<int>(n + 1, -1));
        for (int t = 0; t <= n; t++) {
            if (t % sq[0] == 0) {
                dp[0][t] = t / sq[0];
            } else {
                dp[0][t] = 1e9;
            }
        }
        for (int i = 1; i < len; i++) {
            for (int t = 0; t <= n; t++) {
                int notTake = 0 + dp[i - 1][t];
                int take = INT_MAX;
                if (sq[i] <= t) {
                    take = 1 + dp[i][t - sq[i]];
                }
                dp[i][t] = min(take, notTake);
            }
        }
        int ans = dp[len - 1][n];
        if (ans >= 1e9) {
            return -1;
        }
        return ans;
    }
};