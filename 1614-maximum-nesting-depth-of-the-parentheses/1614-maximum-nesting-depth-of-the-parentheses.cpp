class Solution {
public:
    int maxDepth(string s) {
        int ans = 0, depth = 0;
        for (char ch : s) {
            depth += (ch == '(') - (ch == ')');
            ans = max(ans, depth);
        }
        return ans;
    }
};