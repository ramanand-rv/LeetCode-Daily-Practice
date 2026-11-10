function climbStairs(n: number, costs: number[]): number {
    // dp[j] stores the minimum cost to reach step j
    const dp: number[] = new Array(n + 1).fill(Infinity);
    dp[0] = 0; // Starting at step 0 costs nothing

    for (let j = 1; j <= n; j++) {
        // Try jumping from the previous 1, 2, or 3 steps
        for (let k = 1; k <= 3; k++) {
            const i = j - k; // The step we are jumping from
            if (i >= 0) {
                const jumpCost = (j - i) * (j - i); // Squared jump distance
                // Update min cost
                dp[j] = Math.min(dp[j], dp[i] + costs[j - 1] + jumpCost);
            }
        }
    }

    return dp[n];
}