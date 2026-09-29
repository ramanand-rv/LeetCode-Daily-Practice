function hasValidPath(grid: string[][]): boolean {
    const rows = grid.length;
    const cols = grid[0].length;

    if (grid[0][0] === ')' || grid[rows - 1][cols - 1] === '(') {
        return false;
    }

    if ((rows + cols - 1) % 2 !== 0) {
        return false;
    }

    // memo[row][col][balance] = -1 (unvisited), 0 (false), 1 (true)
    const memo: number[][][] = Array.from({ length: rows }, () =>
        Array.from({ length: cols }, () => new Array(rows + cols).fill(-1))
    );

    function dfs(row: number, col: number, balance: number): boolean {
        if (grid[row][col] === '(') {
            balance++;
        } else {
            balance--;
        }

        if (balance < 0) {
            return false;
        }

        if (row === rows - 1 && col === cols - 1) {
            return balance === 0;
        }

        if (memo[row][col][balance] !== -1) {
            return memo[row][col][balance] === 1;
        }

        let valid = false;

        if (row + 1 < rows) {
            valid = dfs(row + 1, col, balance);
        }

        if (!valid && col + 1 < cols) {
            valid = dfs(row, col + 1, balance);
        }

        memo[row][col][balance] = valid ? 1 : 0;
        return valid;
    }

    return dfs(0, 0, 0);
}