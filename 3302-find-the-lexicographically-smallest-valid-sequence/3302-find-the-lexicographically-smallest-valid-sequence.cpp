class Solution {
public:
    vector<int> validSequence(string s, string t) {
        int n = s.size(), m = t.size();
        vector<int> dp(n + 1, 0);
        int j = m - 1;
        for (int i = n - 1; i >= 0; i--) {
            if (j >= 0 && s[i] == t[j]) {
                dp[i] = dp[i + 1] + 1;
                j--;
            } else {
                dp[i] = dp[i + 1];
            }
        }

        vector<int> ans;
        j = 0;
        bool mismatchUsed = true; // true means we can still use a mismatch

        for (int i = 0; i < n && j < m; i++) {
            int rem = m - j - 1;
            if (s[i] == t[j]) {
                ans.push_back(i);
                j++;
            } else if (mismatchUsed && dp[i + 1] >= rem) {
                ans.push_back(i);
                j++;
                mismatchUsed = false;
            }
        }

        if (j == m) return ans;
        return {};
    }
};