vector<int> dp[9]; // let 0 denote for '(' & 1 for ')'
class Solution {
public:
    static void computeDP() {
        if (!dp[0].empty())
            return; // compute once
        dp[0] = {0};
        for (int i = 1; i <= 8; i++) {
            for (int j = 1; j <= i; j++) {
                for (int x : dp[j - 1])
                    for (int y : dp[i - j]) {
                        // LSB
                        const int z =
                            (y << (2 * j)) | (1 << (2 * j - 1)) | (x << 1);
                        dp[i].push_back(z);
                    }
            }
            //    cout<<dp[i].size()<<endl;
        }
    }
    static inline string to_str(int x, int n) {
        string ans(n << 1, '(');
        for (int i = 0; i < n * 2 && x; i++, x >>= 1) {
            ans[i] = '(' + (x & 1);
        }
        return ans;
    }
    static vector<string> generateParenthesis(int n) {
        computeDP();
        int sz = dp[n].size();
        vector<string> ans(sz);
        int i = 0;
        for (int x : dp[n])
            ans[i++] = to_str(x, n);
        return ans;
    }
};