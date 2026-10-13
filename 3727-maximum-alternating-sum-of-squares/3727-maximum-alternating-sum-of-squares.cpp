class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;
        for (int& x : nums) {
            x = abs(x);
        }
        sort(begin(nums), end(nums));
        int l = 0;
        int r = n - 1;
        while (l < r) {
            ans += 1LL * nums[r] * nums[r];
            ans -= 1LL * nums[l] * nums[l];
            r--;
            l++;
        }
        if (l == r) {
            ans += 1LL * nums[l] * nums[l];
        }
        return ans;
    }
};