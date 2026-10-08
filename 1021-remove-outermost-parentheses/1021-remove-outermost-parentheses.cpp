class Solution {
public:
    string removeOuterParentheses(string s) {
        int open = 0;
        string result;
        for (int i = 0; i < s.size(); i++) {
            char p = s[i];
            if (p == '(') {
                if (open > 0) {
                    result += p;
                }
                open++;
            } else {
                open--;
                if (open > 0) {
                    result += p;
                }
            }
        }
        return result;
    }
};