impl Solution {
    pub fn stone_game_v(stone_value: Vec<i32>) -> i32 {
        let n = stone_value.len();
        let mut prefix = vec![0i64; n + 1];
        for i in 0..n {
            prefix[i + 1] = prefix[i] + stone_value[i] as i64;
        }

        let mut dp = vec![vec![0; n]; n];
        let mut left_best = vec![vec![0; n]; n];
        let mut right_best = vec![vec![0; n]; n];

        // Use i32 for pointers to allow -1 sentinel
        let mut left_ptr: Vec<i32> = vec![-1; n];
        let mut right_ptr: Vec<i32> = vec![0; n];

        for i in 0..n {
            left_best[i][i] = stone_value[i];
            right_best[i][i] = stone_value[i];
            left_ptr[i] = i as i32 - 1;
            right_ptr[i] = i as i32;
        }

        for len in 2..=n {
            for l in 0..=n - len {
                let r = l + len - 1;
                let total = prefix[r + 1] - prefix[l];

                // Move left_ptr[l] forward while condition holds
                while left_ptr[l] + 1 <= (r - 1) as i32 {
                    let k = (left_ptr[l] + 1) as usize;
                    let left_sum = prefix[k + 1] - prefix[l];
                    if 2 * left_sum > total { break; }
                    left_ptr[l] += 1;
                }

                // Move right_ptr[l] forward while condition holds
                while right_ptr[l] <= (r - 1) as i32 {
                    let k = right_ptr[l] as usize;
                    let left_sum = prefix[k + 1] - prefix[l];
                    if 2 * left_sum >= total { break; }
                    right_ptr[l] += 1;
                }

                let mut best = 0;
                if left_ptr[l] >= l as i32 {
                    let idx = left_ptr[l] as usize;
                    best = left_best[l][idx];
                }
                if right_ptr[l] <= (r - 1) as i32 {
                    let idx = (right_ptr[l] + 1) as usize;
                    best = best.max(right_best[idx][r]);
                }

                dp[l][r] = best;
                let total_int = total as i32;
                left_best[l][r] = left_best[l][r - 1].max(dp[l][r] + total_int);
                right_best[l][r] = right_best[l + 1][r].max(dp[l][r] + total_int);
            }
        }

        dp[0][n - 1]
    }
}