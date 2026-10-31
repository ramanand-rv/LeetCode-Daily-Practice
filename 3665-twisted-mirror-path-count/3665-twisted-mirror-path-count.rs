impl Solution {
    pub fn unique_paths(grid: Vec<Vec<i32>>) -> i32 {
        const MOD: i64 = 1_000_000_007;
        let n = grid[0].len();

        let mut down = vec![0i64; n];
        down[0] = 1;

        for row in &grid {
            let mut right = 0i64;

            for j in 0..n {
                if row[j] != 0 {
                    std::mem::swap(&mut right, &mut down[j]);
                } else {
                    let val = (right + down[j]) % MOD;
                    right = val;
                    down[j] = val;
                }
            }
        }

        down[n - 1] as i32
    }
}