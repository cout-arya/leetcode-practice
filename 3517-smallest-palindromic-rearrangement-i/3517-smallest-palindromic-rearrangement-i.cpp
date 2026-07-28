class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.size();
        string res;
        sort(s.begin(), s.begin() + n / 2);
        for (int i = 0; i < n / 2; i++) {
            res += s[i];
        }
        for (int i = (n - 1) / 2; i >= 0; i--) {
            res += s[i];
        }
        return res;
    }
};