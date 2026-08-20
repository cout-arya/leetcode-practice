class Solution {
public:
    void solve(vector<int> nums, vector<vector<int>>& res, int idx) {
        if (idx == size(nums)) {
            res.push_back(nums);
        }
        for (int i = idx; i < nums.size(); ++i) {
            if (i != idx && nums[i] == nums[idx])
                continue;
            swap(nums[i], nums[idx]);
            solve(nums, res, idx + 1);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        sort(begin(nums), end(nums));
        solve(nums, res, 0);
        return res;
    }
};