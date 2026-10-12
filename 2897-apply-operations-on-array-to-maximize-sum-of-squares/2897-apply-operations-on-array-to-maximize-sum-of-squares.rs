impl Solution {
    pub fn max_sum(nums: Vec<i32>, k: i32) -> i32 {
        const MOD: i64 = 1_000_000_007;
        let mut bit_count = vec![0; 32];

        for &num in &nums {
            for b in 0..32 {
                if num & (1 << b) != 0 {
                    bit_count[b] += 1;
                }
            }
        }

        let mut ans: i64 = 0;
        for _ in 0..k {
            let mut cur: i64 = 0;
            for b in 0..32 {
                if bit_count[b] > 0 {
                    bit_count[b] -= 1;
                    cur |= 1 << b;
                }
            }
            let cur_mod = cur % MOD;
            ans = (ans + cur_mod * cur_mod) % MOD;
        }
        ans as i32
    }
}