function createGrid(m: number, n: number): string[] {
    const grid: string[][] = Array.from({ length: m }, () => Array(n).fill('#'));
    let r = 0, c = 0;
    grid[0][0] = '.';

    while (r < m - 1 || c < n - 1) {
        const downErr = r < m - 1
            ? Math.abs((r + 1) * (n - 1) - c * (m - 1))
            : Infinity;

        const rightErr = c < n - 1
            ? Math.abs(r * (n - 1) - (c + 1) * (m - 1))
            : Infinity;

        if (r < m - 1 && downErr <= rightErr) r++;
        else c++;

        grid[r][c] = '.';
    }

    return grid.map(row => row.join(''));
}