impl Solution {
    pub fn num_of_subarrays(arr: Vec<i32>) -> i32 {
        const MOD: i64 = 1_000_000_007;
        let mut even: i64 = 1;
        let mut odd: i64 = 0;
        let mut ans: i64 = 0;
        let mut parity: i32 = 0;

        for x in arr {
            parity = (parity + x) & 1;
            if parity == 1 {
                ans += even;
                odd += 1;
            } else {
                ans += odd;
                even += 1;
            }
            ans %= MOD;
        }

        ans as i32
    }
}