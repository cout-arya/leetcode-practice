class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        int n = s.size();
        unordered_map<string, string> mp;
        for (auto& ch : knowledge) {
            mp[ch[0]] = ch[1];
        }
        string res;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                int j = s.find(")", i + 1);
                string t = s.substr(i + 1, j - i - 1);
                res += mp.count(t) ? mp[t] : "?";
                i = j;
            } else {
                res += s[i];
            }
        }
        return res;
    }
};