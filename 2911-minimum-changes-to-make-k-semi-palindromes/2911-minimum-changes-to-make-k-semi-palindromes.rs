impl Solution {
    pub fn minimum_changes(s: String, k: i32) -> i32 {
        let n = s.len();
        let k = k as usize;
        let inf = 1_000_000_000;
        let bytes = s.as_bytes();
        let mut cost = vec![vec![inf; n]; n];

        // Precompute minimum changes to make any substring a semi-palindrome
        for i in 0..n {
            for j in (i + 1)..n {
                let l = j - i + 1;
                let mut best = inf;
                
                // Try every valid divisor d of length L
                for d in 1..l {
                    if l % d != 0 {
                        continue; // d must divide L
                    }
                    let mut cur = 0;
                    let m = l / d; // Number of interleaved sequences

                    // Check if the d interleaved sequences are palindromes
                    for r in 0..d {
                        for t in 0..(m / 2) {
                            if bytes[i + r + t * d] != bytes[i + r + (m - 1 - t) * d] {
                                cur += 1;
                            }
                        }
                    }
                    if cur < best {
                        best = cur;
                    }
                }
                cost[i][j] = best;
            }
        }

        // DP to partition the string into exactly k semi-palindromes
        let mut dp = vec![vec![inf; k + 1]; n + 1];
        dp[0][0] = 0;

        for i in 1..=n {
            for p in 1..=k {
                // Try all valid previous cut positions (substring length >= 2)
                for prev in 0..(i - 1) {
                    if dp[prev][p - 1] != inf && cost[prev][i - 1] != inf {
                        let val = dp[prev][p - 1] + cost[prev][i - 1];
                        if val < dp[i][p] {
                            dp[i][p] = val;
                        }
                    }
                }
            }
        }

        dp[n][k]
    }
}