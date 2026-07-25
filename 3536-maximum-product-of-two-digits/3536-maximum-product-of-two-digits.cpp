class Solution {
public:
    int maxProduct(int n) {
        int maxd1 = 0, maxd2 = 0;
        for (; n > 0; n /= 10) {
            int d = n % 10;
            if (d >= maxd1) {
                maxd2 = maxd1;
                maxd1 = d;
            } else if (d >= maxd2) {
                maxd2 = d;
            }
        }
        return maxd1 * maxd2;
    }
};