impl Solution {
    pub fn number_of_sets(n: i32, k: i32) -> i32 {
        const MOD: i64 = 1_000_000_007;
        let n = n as usize;
        let k = k as usize;

        let mut dp = vec![vec![0i64; k + 1]; n];

        // 0 segments → 1 way
        for i in 0..n {
            dp[i][0] = 1;
        }

        for j in 1..=k {
            let mut sum = 0i64;
            for i in 1..n {
                sum = (sum + dp[i - 1][j - 1]) % MOD;
                dp[i][j] = (dp[i - 1][j] + sum) % MOD;
            }
        }

        dp[n - 1][k] as i32
    }
}