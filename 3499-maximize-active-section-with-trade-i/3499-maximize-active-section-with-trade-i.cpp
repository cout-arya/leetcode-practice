class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int ones = 0;
        for (char c : s) {
            if (c == '1') {
                ones++;
            }
        }
        s = '1' + s + '1';
        int n = s.size();
        int i = 0;
        int ans = 0;
        while (i < n && s[i] == '1') {
            i++;
        }
        int a = 0;
        while (i < n && s[i] == '0') {
            i++;
            a++;
        }
        while (i < n) {
            int b = 0;
            while (s[i] == '1') {
                i++;
                b++;
            }
            if (b == 0) {
                break;
            }
            int c = 0;
            while (i < n && s[i] == '0') {
                i++;
                c++;
            }
            if (c == 0) {
                break;
            }
            int gain = a + c;
            ans = max(ans, gain);
            a = c;
        }
        return ones + ans;
    }
};