/*
impl Solution {
    pub fn create_grid(m: i32, n: i32) -> Vec<String> {
        let m = m as usize;
        let n = n as usize;
        let mut grid = vec![vec!['#'; n]; m];

        let mut r = 0usize;
        let mut c = 0usize;
        grid[0][0] = '.';

        while r < m - 1 || c < n - 1 {
            let down_err = if r < m - 1 {
                (((r + 1) as i64 * (n as i64 - 1)) - (c as i64 * (m as i64 - 1))).abs()
            } else {
                i64::MAX
            };

            let right_err = if c < n - 1 {
                ((r as i64 * (n as i64 - 1)) - ((c + 1) as i64 * (m as i64 - 1))).abs()
            } else {
                i64::MAX
            };

            if r < m - 1 && down_err <= right_err {
                r += 1;
            } else {
                c += 1;
            }

            grid[r][c] = '.';
        }

        grid.into_iter()
            .map(|row| row.into_iter().collect())
            .collect()
    }
}
*/

impl Solution {
    pub fn create_grid(m: i32, n: i32) -> Vec<String> {
        let m = m as usize;
        let n = n as usize;

        let row = format!(".{}", "#".repeat(n - 1));
        let bottom = ".".repeat(n);

        let mut res = vec![row; m - 1];
        res.push(bottom);
        res
    }
}