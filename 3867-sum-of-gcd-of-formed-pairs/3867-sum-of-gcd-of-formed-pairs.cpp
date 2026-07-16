class Solution {
public:
    int gcd(int a, int b) {
        while (b != 0) {
            int rem = a % b;
            a = b;
            b = rem;
        }
        return a;
    }
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        int mx = 0;
        vector<int> prefGcd;
        for (int i = 0; i < n; i++) {
            mx = max(nums[i], mx);
            prefGcd.push_back(gcd(nums[i], mx));
        }
        sort(prefGcd.begin(), prefGcd.end());
        int l = 0;
        int r = n - 1;
        long long sum = 0;
        while (l < r) {
            sum += gcd(prefGcd[l], prefGcd[r]);
            l++;
            r--;
        }
        return sum;
    }
};