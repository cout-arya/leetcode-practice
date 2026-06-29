class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int totalSum = 0;
        for (int x : nums)
            totalSum += x;
        if (abs(target) > totalSum || (totalSum - target) % 2)
            return 0;
        int s2 = (totalSum - target) / 2;
        vector<vector<int>> dp(n + 1, vector<int>(s2 + 1, 0));
        dp[0][0] = 1;
        for (int i = 1; i <= n; i++) {
            for (int t = 0; t <= s2; t++) {
                dp[i][t] = dp[i - 1][t];
                if (nums[i - 1] <= t)
                    dp[i][t] += dp[i - 1][t - nums[i - 1]];
            }
        }
        return dp[n][s2];
    }
};