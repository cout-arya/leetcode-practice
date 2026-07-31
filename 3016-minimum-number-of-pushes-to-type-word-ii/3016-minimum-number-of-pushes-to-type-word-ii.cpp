class Solution {
public:
    int minimumPushes(string word) {
        int pushes = 0;
        vector<int> freq(26, 0);
        for (char c : word) {
            freq[c - 'a']++;
        }
        sort(freq.begin(), freq.end(), greater<int>());
        for (int i = 0; i < 26; i++) {
            pushes += freq[i] * (i / 8 + 1);
        }
        return pushes;
    }
};