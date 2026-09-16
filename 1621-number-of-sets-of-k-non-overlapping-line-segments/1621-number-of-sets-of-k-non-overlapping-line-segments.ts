function numberOfSets(n: number, k: number): number {
    const MOD = 1_000_000_007;
    const dp: number[][] = Array.from({ length: n }, () => Array(k + 1).fill(0));

    // 0 segments → 1 way
    for (let i = 0; i < n; i++) dp[i][0] = 1;

    for (let j = 1; j <= k; j++) {
        let sum = 0;
        for (let i = 1; i < n; i++) {
            sum = (sum + dp[i - 1][j - 1]) % MOD;
            dp[i][j] = (dp[i - 1][j] + sum) % MOD;
        }
    }

    return dp[n - 1][k];
}