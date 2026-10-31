function uniquePaths(grid: number[][]): number {
    const MOD = 1_000_000_007;
    const n = grid[0].length;

    const down = new Array(n).fill(0);
    down[0] = 1;

    for (const row of grid) {
        let right = 0;

        for (let j = 0; j < n; j++) {
            if (row[j] !== 0) {
                // mirror: swap flows
                [right, down[j]] = [down[j], right];
            } else {
                // empty: merge flows
                right = down[j] = (right + down[j]) % MOD;
            }
        }
    }

    return down[n - 1];
}