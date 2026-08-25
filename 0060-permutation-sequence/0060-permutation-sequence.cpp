class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int l = 0;
        int r = n - 2;
        while (r >= 0 && nums[r] >= nums[r + 1]) {
            r--;
        }
        if (r < 0) {
            reverse(nums.begin(), nums.end());
            return;
        }
        l = r;
        int nge = INT_MAX;
        for (int i = l + 1; i < n; i++) {
            if (nums[i] > nums[l] && nums[i] < nge) {
                nge = nums[i];
                r = i;
            }
        }
        swap(nums[l], nums[r]);
        sort(nums.begin() + l + 1, nums.end());
    }
    string getPermutation(int n, int k) {
        vector<int> perm;
        for (int i = 1; i <= n; i++) {
            perm.push_back(i);
        }
        for (int j = 0; j < k - 1; j++) {
            nextPermutation(perm);
        }
        string res;
        for (int n : perm) {
            res += to_string(n);
        }
        return res;
    }
};