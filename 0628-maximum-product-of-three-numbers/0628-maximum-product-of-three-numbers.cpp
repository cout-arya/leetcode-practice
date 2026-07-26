class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int a = -1001, b = a, c = b;
        int x = 1001, y = x;
        for (auto &n : nums) {
            int a1 = a, b1 = b, x1 = x;
            a = max(a, n);
            b = max(b, min(a1, n));
            c = max(c, min(b1, n));

            x = min(x, n);
            y = min(y, max(x1, n));
        }
        return max(a * b * c, x * y * a);
    }
};