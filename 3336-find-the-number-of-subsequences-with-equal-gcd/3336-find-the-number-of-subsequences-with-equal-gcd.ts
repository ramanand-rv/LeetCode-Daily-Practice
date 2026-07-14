function subsequencePairCount(nums: number[]): number {
    const MOD = 1_000_000_007;
    const n = nums.length;
    const MAX = 200;

    const gcd = (a: number, b: number): number => {
        while (b) { [a, b] = [b, a % b]; }
        return a;
    };

    // 3D memo table dp[idx][g1][g2] = number of ways
    const dp: number[][][] = Array.from({ length: n }, () =>
        Array.from({ length: MAX + 1 }, () => new Array(MAX + 1).fill(-1))
    );

    const solve = (idx: number, g1: number, g2: number): number => {
        if (idx === n) {
            return (g1 !== 0 && g1 === g2) ? 1 : 0;
        }

        if (dp[idx][g1][g2] !== -1) return dp[idx][g1][g2];

        let ans = 0;

        // Ignore
        ans = solve(idx + 1, g1, g2);

        // Put in seq1
        const ng1 = (g1 === 0) ? nums[idx] : gcd(g1, nums[idx]);
        ans = (ans + solve(idx + 1, ng1, g2)) % MOD;

        // Put in seq2
        const ng2 = (g2 === 0) ? nums[idx] : gcd(g2, nums[idx]);
        ans = (ans + solve(idx + 1, g1, ng2)) % MOD;

        dp[idx][g1][g2] = ans;
        return ans;
    };

    return solve(0, 0, 0);
}