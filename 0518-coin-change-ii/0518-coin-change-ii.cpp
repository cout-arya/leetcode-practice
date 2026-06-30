class Solution {
public:
    int solve(auto &coins, int i, int amount, auto &dp)
    {
        if (amount == 0)
            return 1;

        if (i == coins.size() - 1)
            return (amount % coins[i] == 0);

        if (dp[i][amount] != -1)
            return dp[i][amount];

        int pick = 0;
        if (coins[i] <= amount)
            pick = solve(coins, i, amount - coins[i], dp);

        int notPick = solve(coins, i + 1, amount, dp);

        return dp[i][amount] = pick + notPick;
    }

    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));

        return solve(coins, 0, amount, dp);
    }
};