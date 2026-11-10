impl Solution {
    pub fn climb_stairs(n: i32, costs: Vec<i32>) -> i32 {
        let n = n as usize;
        // dp[j] stores the minimum cost to reach step j
        let mut dp = vec![i64::MAX; n + 1];
        dp[0] = 0; // Starting at step 0 costs nothing

        for j in 1..=n {
            // Try jumping from the previous 1, 2, or 3 steps
            for k in 1..=3 {
                if j >= k {
                    let i = j - k; // The step we are jumping from
                    let jump_cost = (k * k) as i64; // Squared jump distance
                    // Update min cost
                    dp[j] = dp[j].min(dp[i] + costs[j - 1] as i64 + jump_cost);
                }
            }
        }

        dp[n] as i32
    }
}