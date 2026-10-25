function closedIsland(grid: number[][]): number {
    const m = grid.length, n = grid[0].length;

    function closed(i: number, j: number): boolean {
        if (i < 0 || i >= m || j < 0 || j >= n) return false;
        if (grid[i][j] === 1) return true;

        grid[i][j] = 1; // mark visited

        const a = closed(i + 1, j);
        const b = closed(i - 1, j);
        const c = closed(i, j + 1);
        const d = closed(i, j - 1);

        return a && b && c && d; // all calls already executed
    }

    let count = 0;
    for (let i = 0; i < m; i++) {
        for (let j = 0; j < n; j++) {
            if (grid[i][j] === 0 && closed(i, j)) count++;
        }
    }
    return count;
}