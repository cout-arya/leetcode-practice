class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        int l = 0, r = 0;
        int ones = 0;
        string res = "";
        while (r < n) {
            if (s[r] == '1')
                ones++;
            while (ones > k) {
                if (s[l] == '1')
                    ones--;
                l++;
            }
            while (ones == k && s[l] == '0') {
                l++;
            }
            if (ones == k) {
                string curr = s.substr(l, r - l + 1);

                if (res.empty() || curr.size() < res.size() ||
                    (curr.size() == res.size() && curr < res)) {
                    res = curr;
                }
            }
            r++;
        }
        return res;
    }
};