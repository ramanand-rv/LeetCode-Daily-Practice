impl Solution {
    pub fn score_of_parentheses(s: String) -> i32 {
        let bytes = s.as_bytes();
        let mut ans = 0;
        let mut bal = 0;
        for i in 0..bytes.len() {
            if bytes[i] == b'(' {
                bal += 1;
            } else {
                bal -= 1;
                if i > 0 && bytes[i - 1] == b'(' {
                    ans += 1 << bal;
                }
            }
        }
        ans
    }
}