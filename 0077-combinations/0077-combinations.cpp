class Solution {
public:
    void solve(int i, vector<int>& arr, vector<vector<int>>& res, int n,
               int k) {
        if (arr.size() == k) {
            res.push_back(arr);
            return;
        }
        for (int num = i; num <= n; num++) {
            arr.push_back(num);
            solve(num + 1, arr, res, n, k);
            arr.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> arr;
        solve(1, arr, res, n, k);
        return res;
    }
};