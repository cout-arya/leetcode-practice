class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<long>> prev(2, vector<long>(3, 0));
        vector<vector<long>> curr(2, vector<long>(3, 0));
        for (int i = n - 1; i >= 0; i--) {
            for (int buy = 0; buy <= 1; buy++) {
                for (int rem = 1; rem <= 2; rem++) {
                    long profit = 0;
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
        return prev[0][2];
    }
};