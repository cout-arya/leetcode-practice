class Solution {
public:
    int smallestNumber(int n, int t) {
        while (true) {
            int x = n;
            int sum = 1;
            while (x > 0) {
                int rem = x % 10;
                sum *= rem;
                x /= 10;
            }
            if (sum % t == 0) {
                return n;
            }
            n++;
        }
    }
};