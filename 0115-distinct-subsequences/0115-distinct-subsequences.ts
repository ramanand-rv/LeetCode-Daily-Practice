function numDistinct(s: string, t: string): number {
    const MOD = 1e9 + 7;
    const n = s.length,
        m = t.length;
    const dp: number[] = Array(m + 1).fill(0);
    dp[0] = 1;

    for (let i = 1; i <= n; i++) {
        let prev = dp[0];
        for (let j = 1; j <= m; j++) {
            const cur = dp[j];
            if (s[i - 1] === t[j - 1]) {
                dp[j] = (dp[j] + prev) % MOD;
            }
            prev = cur;
        }
    }
    return dp[m];
}