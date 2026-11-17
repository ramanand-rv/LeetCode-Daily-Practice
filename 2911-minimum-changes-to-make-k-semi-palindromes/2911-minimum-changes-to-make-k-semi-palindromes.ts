function minimumChanges(s: string, k: number): number {
    const n = s.length;
    const INF = 1e9;
    const cost: number[][] = Array.from({ length: n }, () => new Array(n).fill(INF));

    // Precompute minimum changes to make any substring a semi-palindrome
    for (let i = 0; i < n; i++) {
        for (let j = i + 1; j < n; j++) {
            const L = j - i + 1;
            let best = INF;

            // Try every valid divisor d of length L
            for (let d = 1; d < L; d++) {
                if (L % d !== 0) continue; // d must divide L
                let cur = 0;
                const m = Math.floor(L / d); // Number of interleaved sequences

                // Check if the d interleaved sequences are palindromes
                for (let r = 0; r < d; r++) {
                    for (let t = 0; t < Math.floor(m / 2); t++) {
                        if (s[i + r + t * d] !== s[i + r + (m - 1 - t) * d]) {
                            cur++;
                        }
                    }
                }
                best = Math.min(best, cur);
            }
            cost[i][j] = best;
        }
    }

    // DP to partition the string into exactly k semi-palindromes
    const dp: number[][] = Array.from({ length: n + 1 }, () => new Array(k + 1).fill(INF));
    dp[0][0] = 0;

    for (let i = 1; i <= n; i++) {
        for (let p = 1; p <= k; p++) {
            // Try all valid previous cut positions (substring length >= 2)
            for (let prev = 0; prev < i - 1; prev++) {
                if (dp[prev][p - 1] !== INF && cost[prev][i - 1] !== INF) {
                    dp[i][p] = Math.min(dp[i][p], dp[prev][p - 1] + cost[prev][i - 1]);
                }
            }
        }
    }
    return dp[n][k];
}