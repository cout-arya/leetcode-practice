class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& arr) {
        int n = arr.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            bool cover = false;
            for (int j = 0; j < n; j++) {
                if (i == j) {
                    continue;
                }
                if (arr[j][0] <= arr[i][0] && arr[i][1] <= arr[j][1]) {
                    cover = true;
                    break;
                }
            }
            if (!cover) {
                ++ans;
            }
        }
        return ans;
    }
};