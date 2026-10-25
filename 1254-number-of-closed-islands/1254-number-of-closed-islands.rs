impl Solution {
    pub fn closed_island(mut grid: Vec<Vec<i32>>) -> i32 {
        let m = grid.len() as i32;
        let n = grid[0].len() as i32;

        fn closed(grid: &mut Vec<Vec<i32>>, i: i32, j: i32, m: i32, n: i32) -> bool {
            if i < 0 || i >= m || j < 0 || j >= n {
                return false;
            }
            let (ui, uj) = (i as usize, j as usize);
            if grid[ui][uj] == 1 {
                return true;
            }

            grid[ui][uj] = 1; // mark visited

            let a = closed(grid, i + 1, j, m, n);
            let b = closed(grid, i - 1, j, m, n);
            let c = closed(grid, i, j + 1, m, n);
            let d = closed(grid, i, j - 1, m, n);

            a && b && c && d
        }

        let mut count = 0;
        for i in 0..m {
            for j in 0..n {
                if grid[i as usize][j as usize] == 0 && closed(&mut grid, i, j, m, n) {
                    count += 1;
                }
            }
        }
        count
    }
}