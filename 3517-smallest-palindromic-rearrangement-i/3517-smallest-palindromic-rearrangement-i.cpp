class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.size();
        string res(n,' ');
        vector<int> freq(26, 0);
        for (char c : s) {
            freq[c - 'a']++;
        }
        int l = 0, r = n - 1;
        for (int i = 0; i < 26; i++) {
            while (freq[i] >= 2) {
                res[l] = char('a' + i);
                res[r] = char('a' + i);
                l++;
                r--;
                freq[i] -= 2;
            }
            if (freq[i] == 1) {
                res[n / 2] = char('a' + i);
            }
        }
        return res;
    }
};