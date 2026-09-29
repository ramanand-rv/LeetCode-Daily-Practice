impl Solution {
    pub fn has_valid_path(grid: Vec<Vec<char>>) -> bool {
        let rows = grid.len();
        let cols = grid[0].len();

        if grid[0][0] == ')' || grid[rows-1][cols-1] == '(' {
            return false;
        }

        if (rows + cols - 1) % 2 != 0 {
            return false;
        }

        // memo[row][col][balance] = -1 (unvisited), 0 (false), 1 (true)
        let mut memo = vec![vec![vec![-1i8; rows + cols]; cols]; rows];

        fn dfs(
            grid: &Vec<Vec<char>>,
            memo: &mut Vec<Vec<Vec<i8>>>,
            row: usize,
            col: usize,
            balance: i32,
        ) -> bool {
            let rows = grid.len();
            let cols = grid[0].len();

            let mut bal = balance;
            if grid[row][col] == '(' {
                bal += 1;
            } else {
                bal -= 1;
            }

            if bal < 0 {
                return false;
            }

            if row == rows - 1 && col == cols - 1 {
                return bal == 0;
            }

            let bal_idx = bal as usize;
            if memo[row][col][bal_idx] != -1 {
                return memo[row][col][bal_idx] == 1;
            }

            let mut valid = false;

            if row + 1 < rows {
                valid = dfs(grid, memo, row + 1, col, bal);
            }

            if !valid && col + 1 < cols {
                valid = dfs(grid, memo, row, col + 1, bal);
            }

            memo[row][col][bal_idx] = if valid { 1 } else { 0 };
            valid
        }

        dfs(&grid, &mut memo, 0, 0, 0)
    }
}