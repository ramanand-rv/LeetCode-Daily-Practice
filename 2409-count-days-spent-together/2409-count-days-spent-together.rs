impl Solution {
    pub fn count_days_together(
        arrive_alice: String,
        leave_alice: String,
        arrive_bob: String,
        leave_bob: String,
    ) -> i32 {
        fn f(s: &str) -> i32 {
            let b = s.as_bytes();
            let m = ((b[0] - b'0') * 10 + (b[1] - b'0')) as i32;
            let q = ((b[3] - b'0') * 10 + (b[4] - b'0')) as i32;
            (275 * m) / 9 - 2 * ((m + 9) / 12) + q - 30
        }

        let a = f(&arrive_alice);
        let b = f(&leave_alice);
        let c = f(&arrive_bob);
        let d = f(&leave_bob);

        0.max(b.min(d) - a.max(c) + 1)
    }
}