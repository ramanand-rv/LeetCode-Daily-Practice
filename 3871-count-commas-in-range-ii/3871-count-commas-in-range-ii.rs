impl Solution {
    pub fn count_commas(n: i64) -> i64 {
        if n <= 999 { return 0; }
        let mut total = 0;
        let mut start = 1000;
        while start <= n {
            total += n - start + 1;
            start *= 1000;
        }
        total
    }
}