class Solution {
    int MOD = 1e9 + 7;
public:
    int gcd(int a, int b) {
        while (b != 0) {
            int rem = a % b;
            a = b;
            b = rem;
        }
        return a;
    }
    int subsequencePairCount(vector<int>& nums) {
        int n = nums.size();

        int maxEl = -1;
        for (int x : nums)
            maxEl = max(maxEl, x);

        int dp[n + 1][maxEl + 1][maxEl + 1];

        for (int first = 0; first <= maxEl; first++) {
            for (int second = 0; second <= maxEl; second++) {
                bool bothNonEmpty = (first != 0 && second != 0);
                bool gcdsMatch = (first == second);
                dp[n][first][second] = (bothNonEmpty && gcdsMatch) ? 1 : 0;
            }
        }
        for (int i = n - 1; i >= 0; i--) {
            for (int first = maxEl; first >= 0; first--) {
                for (int second = maxEl; second >= 0; second--) {

                    int skip = dp[i + 1][first][second];
                    int take1 = dp[i + 1][gcd(first, nums[i])][second];
                    int take2 = dp[i + 1][first][gcd(second, nums[i])];

                    dp[i][first][second] = (0LL + skip + take1 + take2) % MOD;
                }
            }
        }
        return dp[0][0][0];
    }
};