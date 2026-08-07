class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n);
        dp[0] = 1;
        int p1 = 0;
        int p2 = 0;
        int p3 = 0;
        for (int i = 1; i < n; i++) {
            int m2 = dp[p1] * 2;
            int m3 = dp[p2] * 3;
            int m5 = dp[p3] * 5;

            dp[i] = min(m2, min(m3, m5));

            if (dp[i] == m2)
                p1++;
            if (dp[i] == m3)
                p2++;
            if (dp[i] == m5)
                p3++;
        }
        return dp[n - 1];
    }
};