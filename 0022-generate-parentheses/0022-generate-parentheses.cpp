class Solution {
public:
    vector<string> ans;
    void preOrder(int lp, int rp, int level, string&& fromRoot, int n) {
        if (lp == n && rp == n && level == 0)
            ans.push_back(fromRoot);
        if (lp < n)
            preOrder(lp + 1, rp, level + 1, fromRoot + "(", n);
        if (rp < n && level >= 1)
            preOrder(lp, rp + 1, level - 1, fromRoot + ")", n);
    }
    vector<string> generateParenthesis(int n) {
        ans.reserve(n << 1);
        preOrder(1, 0, 1, "(", n);
        return ans;
    }
};