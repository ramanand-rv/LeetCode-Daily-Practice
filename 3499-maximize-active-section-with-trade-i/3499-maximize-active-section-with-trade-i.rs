impl Solution {
    pub fn max_active_sections_after_trade(s: String) -> i32 {
        let s = s.as_bytes();
        let n = s.len();
        let mut prev_zero = 0;
        let mut curr_zero = 0;
        let mut total_ones = 0;
        let mut best = 0;
        let mut i = 0;

        while i < n {
            if s[i] == b'0' {
                prev_zero += 1;
                i += 1;
            } else {
                while i < n && s[i] == b'1' {
                    total_ones += 1;
                    i += 1;
                }
                while i < n && s[i] == b'0' {
                    curr_zero += 1;
                    i += 1;
                }
                if prev_zero > 0 && curr_zero > 0 {
                    best = best.max(prev_zero + curr_zero);
                }
                prev_zero = curr_zero;
                curr_zero = 0;
            }
        }
        total_ones + best
    }
}