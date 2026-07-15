class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<long long>> prev(2, vector<long long>(k + 1, 0));
        vector<vector<long long>> curr(2, vector<long long>(k + 1, 0));
        for (int i = n - 1; i >= 0; i--) {
            for (int buy = 0; buy <= 1; buy++) {
                for (int rem = 1; rem <= k; rem++) {
                    if (buy == 0) {
                        curr[buy][rem] =
                            max(-prices[i] + prev[1][rem], prev[0][rem]);
                    } else {
                        curr[buy][rem] =
                            max(prices[i] + prev[0][rem - 1], prev[1][rem]);
                    }
                }
            }
            prev = curr;
        }
        return prev[0][k];
    }
};