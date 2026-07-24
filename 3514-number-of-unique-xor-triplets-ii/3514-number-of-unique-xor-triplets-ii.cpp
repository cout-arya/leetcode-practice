class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        const int M = 2048;
        vector<vector<int>> dp(4, vector<int>(M));
        dp[0][0] = 1;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < M; j++) {
                if (!dp[i][j])
                    continue;
                for (int v : nums)
                    dp[i + 1][j ^ v] = 1;
            }
        }
        int ans = 0;
        for (int x = 0; x < M; x++) {
            if (dp[3][x])
                ans++;
        }
        return ans;
    }
};