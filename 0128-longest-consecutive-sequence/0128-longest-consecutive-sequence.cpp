class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> s(nums.begin(), nums.end());
        int ans = 0;
        for (int it : s) {
            if (s.find(it - 1) == s.end()) {
                int curr = it;
                int currStreak = 1;
                while (s.find(curr + 1) != s.end()) {
                    curr++;
                    currStreak++;
                }
                ans = max(ans, currStreak);
            }
        }
        return ans;
    }
};