impl Solution {
    pub fn max_depth(s: String) -> i32 {
        let mut ans = 0;
        let mut depth = 0;
        for ch in s.chars() {
            depth += (ch == '(') as i32 - (ch == ')') as i32;
            ans = ans.max(depth);
        }
        ans
    }
}