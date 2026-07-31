class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> freq(26, 0);
        int l = 0, r = 0;
        int maxCount = 0;
        int maxLen = 0;
        while (r < s.size()) {
            freq[s[r] - 'A']++;
            maxCount = max(maxCount, freq[s[r] - 'A']);
            while ((r - l + 1) - maxCount > k) {
                freq[s[l] - 'A']--;
                l++;
            }
            maxLen = max(maxLen, r - l + 1);
            r++;
        }
        return maxLen;
    }
};