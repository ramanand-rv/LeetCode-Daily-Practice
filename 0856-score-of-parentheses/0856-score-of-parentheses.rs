impl Solution {
    pub fn score_of_parentheses(s: String) -> i32 {
        fn f(s: &[u8], i: usize, j: usize) -> i32 {
            let mut ans = 0;
            let mut bal = 0;
            let mut i = i;
            for k in i..j {
                bal += if s[k] == b'(' { 1 } else { -1 };
                if bal == 0 {
                    if k - i == 1 {
                        ans += 1;
                    } else {
                        ans += 2 * f(s, i + 1, k);
                    }
                    i = k + 1;
                }
            }
            ans
        }
        f(s.as_bytes(), 0, s.len())
    }
}