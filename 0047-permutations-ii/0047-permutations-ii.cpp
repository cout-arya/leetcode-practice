class Solution {
public:
    void solve(vector<int> nums, vector<vector<int>>& res, int i) {
        if (i == size(nums)) {
            res.push_back(nums);
        }
        for (int j = i; j < nums.size(); ++j) {
            if (j != i && nums[j] == nums[i])
                continue;
            swap(nums[j], nums[i]);
            solve(nums, res, i + 1);
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        sort(begin(nums), end(nums));
        solve(nums, res, 0);
        return res;
    }
};