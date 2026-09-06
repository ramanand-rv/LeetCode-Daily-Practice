impl Solution {
    pub fn num_distinct(s: String, t: String) -> i32 {
        const MOD: i64 = 1_000_000_007;
        let s = s.as_bytes();
        let t = t.as_bytes();
        let n = s.len();
        let m = t.len();
        let mut dp = vec![0; m + 1];
        dp[0] = 1;

        for i in 1..=n {
            let mut prev = dp[0];
            for j in 1..=m {
                let cur = dp[j];
                if s[i - 1] == t[j - 1] {
                    dp[j] = (dp[j] + prev) % MOD;
                }
                prev = cur;
            }
        }
        dp[m] as i32
    }
}