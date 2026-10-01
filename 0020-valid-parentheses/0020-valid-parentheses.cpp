class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (int i = 0; i < s.length(); i++) {
            char p = s[i];
            if (p == '(' || p == '{' || p == '[') {
                st.push(p);
            } else {
                if (!st.empty()) {
                    char top = st.top();
                    if ((top == '(' && p == ')') || (top == '{' && p == '}') ||
                        (top == '[' && p == ']')) {
                        st.pop();
                    } else {
                        return false;
                    }
                } else {
                    return false;
                }
            }
        }
        if (st.empty()) {
            return true;
        } else {
            return false;
        }
    }
};