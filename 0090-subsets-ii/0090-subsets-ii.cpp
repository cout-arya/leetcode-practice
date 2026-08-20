class Solution {
public:
    void solve(int i, vector<int>& nums, vector<int>& subset,
               vector<vector<int>>& res) {
        if (i == nums.size()) {
            res.push_back(subset);
            return;
        }
        subset.push_back(nums[i]);
        solve(i + 1, nums, subset, res);
        subset.pop_back();
        while (i + 1 < nums.size() && nums[i] == nums[i + 1])
            i++;
        solve(i + 1, nums, subset, res);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        vector<int> subset;
        solve(0, nums, subset, res);
        return res;
    }
};