impl Solution {
    pub fn min_add_to_make_valid(s: String) -> i32 {
        let mut open = 0;
        let mut add = 0;
        for c in s.chars() {
            if c == '(' {
                open += 1;
            } else {
                if open > 0 {
                    open -= 1;
                } else {
                    add += 1;
                }
            }
        }
        add + open
    }
}