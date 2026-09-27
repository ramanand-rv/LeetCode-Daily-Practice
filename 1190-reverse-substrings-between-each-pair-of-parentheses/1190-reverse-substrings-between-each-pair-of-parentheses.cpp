class Solution {
public:
    string reverseParentheses(string s) {
        int n = s.length();
        vector<int> match(n);
        stack<int> st;
        for (int i = 0; i < n; ++i) {
            if (s[i] == '(')
                st.push(i);
            else if (s[i] == ')') {
                int j = st.top();
                st.pop();
                match[i] = j;
                match[j] = i;
            }
        }
        string ans;
        ans.reserve(n);
        int i = 0, dir = 1;
        while (i < n) {
            if (s[i] == '(' || s[i] == ')') {
                i = match[i];
                dir = -dir;
            } else {
                ans += s[i];
            }
            i += dir;
        }
        return ans;
    }
};