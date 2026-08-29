class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<int> arr = nums;
        sort(begin(arr), end(arr));
        int grpNum = 0;

        unordered_map<int, int> grp;
        grp[arr[0]] = grpNum;

        unordered_map<int, list<int>> grpToList;
        grpToList[grpNum].push_back(arr[0]);

        for (int i = 1; i < n; i++) {
            if (abs(arr[i] - arr[i - 1]) > limit) {
                grpNum++;
            }
            grp[arr[i]] = grpNum;
            grpToList[grpNum].push_back(arr[i]);
        }
        vector<int> res(n);
        for (int i = 0; i < n; i++) {
            int num = nums[i];
            int group = grp[num];
            res[i] = *grpToList[group].begin();
            grpToList[group].pop_front();
        }
        return res;
    }
};