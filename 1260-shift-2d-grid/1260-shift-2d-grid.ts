function shiftGrid(grid: number[][], k: number): number[][] {
    const m = grid.length;
    const n = grid[0].length;
    const total = m * n;

    k = k % total;

    const ans: number[][] = Array.from({ length: m }, () => Array(n).fill(0));

    for (let i = 0; i < m; i++) {

        for (let j = 0; j < n; j++) {

            const oldIndex = i * n + j;
            const newIndex = (oldIndex + k) % total;
            const newRow = Math.floor(newIndex / n);
            const newCol = newIndex % n;
            
            ans[newRow][newCol] = grid[i][j];
        }
    }
    return ans;
}