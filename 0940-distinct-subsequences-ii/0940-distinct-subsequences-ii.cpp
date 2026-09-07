class Solution {
public:
    int distinctSubseqII(string s) {
        const int MOD = 1e9 + 7;
        vector<int> countEndWith(26, 0);
        int total = 0;

        for (char c : s) {
            int idx = c - 'a';
            int newSubseqs = (1 + total - countEndWith[idx] + MOD) % MOD;
            total = (total + newSubseqs) % MOD;
            countEndWith[idx] = (countEndWith[idx] + newSubseqs) % MOD;
        }
        return total;
    }
};