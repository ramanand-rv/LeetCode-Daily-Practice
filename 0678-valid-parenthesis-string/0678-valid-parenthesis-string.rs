impl Solution {
    pub fn check_valid_string(s: String) -> bool {
        let mut low = 0;
        let mut high = 0;
        for ch in s.chars() {
            match ch {
                '(' => { low += 1; high += 1; }
                ')' => {
                    if low > 0 { low -= 1; }
                    high -= 1;
                }
                _ => { // '*'
                    if low > 0 { low -= 1; }
                    high += 1;
                }
            }
            if high < 0 { return false; }
        }
        low == 0
    }
}