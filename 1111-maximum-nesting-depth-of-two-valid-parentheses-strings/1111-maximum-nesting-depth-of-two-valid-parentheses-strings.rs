impl Solution {
    pub fn max_depth_after_split(seq: String) -> Vec<i32> {
        let mut depth = 0;
        let mut ans = Vec::with_capacity(seq.len());

        for ch in seq.chars() {
            if ch == '(' {
                depth += 1;
                ans.push(depth % 2);
            } else {
                ans.push(depth % 2);
                depth -= 1;
            }
        }

        ans
    }
}