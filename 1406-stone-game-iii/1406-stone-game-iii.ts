function stoneGameIII(stoneValue: number[]): string {
    const n = stoneValue.length;
    const dp: number[] = [0, 0, 0, 0];

    for (let i = n - 1; i >= 0; i--) {
        const idx = i % 4;

        // take 1
        let best = stoneValue[i] - dp[(i + 1) % 4];

        // take 2
        if (i + 1 < n) {
            best = Math.max(best, stoneValue[i] + stoneValue[i + 1] - dp[(i + 2) % 4]);
        }

        // take 3
        if (i + 2 < n) {
            best = Math.max(best, stoneValue[i] + stoneValue[i + 1] + stoneValue[i + 2] - dp[(i + 3) % 4]);
        }

        dp[idx] = best;
    }

    const diff = dp[0];
    return diff > 0 ? "Alice" : diff < 0 ? "Bob" : "Tie";
}