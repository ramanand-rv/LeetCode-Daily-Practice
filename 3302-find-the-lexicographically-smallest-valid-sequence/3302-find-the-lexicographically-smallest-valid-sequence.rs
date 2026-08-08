impl Solution {
    pub fn valid_sequence(s: String, t: String) -> Vec<i32> {
        let s = s.as_bytes();
        let t = t.as_bytes();
        let n = s.len();
        let m = t.len();
        let mut dp = vec![0; n + 1];
        let mut j = m as i32 - 1;
        for i in (0..n).rev() {
            if j >= 0 && s[i] == t[j as usize] {
                dp[i] = dp[i + 1] + 1;
                j -= 1;
            } else {
                dp[i] = dp[i + 1];
            }
        }

        let mut ans = Vec::new();
        let mut j = 0;
        let mut mismatch_used = true;

        for i in 0..n {
            if j == m { break; }
            let rem = (m - j - 1) as i32;
            if s[i] == t[j] {
                ans.push(i as i32);
                j += 1;
            } else if mismatch_used && dp[i + 1] >= rem {
                ans.push(i as i32);
                j += 1;
                mismatch_used = false;
            }
        }

        if j == m { ans } else { Vec::new() }
    }
}