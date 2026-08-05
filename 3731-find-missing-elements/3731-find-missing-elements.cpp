class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        vector<int> res;
        int mini = INT_MAX;
        int maxi = INT_MIN;
        for (int it : nums) {
            maxi = max(maxi, it);
            mini = min(mini, it);
        }
        for (int i = mini; i <= maxi; i++) {
            if (!s.count(i)) {
                res.push_back(i);
            }
        }
        return res;
    }
};