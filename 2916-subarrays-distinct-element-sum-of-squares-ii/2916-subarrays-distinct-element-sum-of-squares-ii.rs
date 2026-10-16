use std::collections::HashMap;

impl Solution {
    pub fn sum_counts(nums: Vec<i32>) -> i32 {
        const MOD: i64 = 1_000_000_007;
        let n = nums.len();
        let mut cnt = vec![0i64; n + 1];
        let mut tot = vec![0i64; n + 1];
        let mut last: HashMap<i32, i32> = HashMap::new();
        let mut ans: i64 = 0;

        for r in 0..n {
            let x = nums[r];
            let p = *last.get(&x).unwrap_or(&-1);

            let mut c: i64 = 0;
            let mut s: i64 = 0;
            let mut i = (n as i32 - p - 1) as usize;
            while i > 0 {
                c += cnt[i];
                s += tot[i];
                i -= i & i.wrapping_neg();
            }

            let gain = ((r as i64 - p as i64) * (r as i64 - p as i64)) - 2 * (s - p as i64 * c);
            ans = (ans + (n as i64 - r as i64) * gain) % MOD;
            if ans < 0 {
                ans += MOD;
            }

            let mut i = (n as i32 - p) as usize;
            while i <= n {
                cnt[i] += 1;
                tot[i] += p as i64;
                i += i & i.wrapping_neg();
            }

            last.insert(x, r as i32);
        }

        ans as i32
    }
}