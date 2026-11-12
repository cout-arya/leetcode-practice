class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size(), best = 1, up = 1, down = 1;
        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1]) {
                up += 1;
            } else {
                up = 1;
            }
            if (nums[i] < nums[i - 1]) {
                down += 1;
            } else {
                down = 1;
            }
            best = max({best, up, down});
        }
        return best;
    }
};