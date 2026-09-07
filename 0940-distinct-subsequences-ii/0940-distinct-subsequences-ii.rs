impl Solution {
    pub fn distinct_subseq_ii(s: String) -> i32 {
        const MOD: i64 = 1_000_000_007;
        let mut end_with = [0; 26];
        let mut total = 0;

        for ch in s.bytes() {
            let idx = (ch - b'a') as usize;
            let new = (1 + total - end_with[idx] + MOD) % MOD;
            total = (total + new) % MOD;
            end_with[idx] = (end_with[idx] + new) % MOD;
        }
        total as i32
    }
}