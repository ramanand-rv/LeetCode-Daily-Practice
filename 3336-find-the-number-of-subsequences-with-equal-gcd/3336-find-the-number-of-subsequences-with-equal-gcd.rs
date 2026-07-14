use std::collections::HashMap;

impl Solution {
    pub fn subsequence_pair_count(nums: Vec<i32>) -> i32 {
        const MOD: i64 = 1_000_000_007;
        let n = nums.len();
        let mut memo = vec![vec![vec![-1; 201]; 201]; n]; // 3D memo

        // gcd 
        fn gcd(a: i32, b: i32) -> i32 {
            let mut a = a;
            let mut b = b;
            while b != 0 {
                let t = a % b;
                a = b;
                b = t;
            }
            a
        }

        fn solve(idx: usize, g1: i32, g2: i32, nums: &Vec<i32>, memo: &mut Vec<Vec<Vec<i64>>>) -> i64 {
            if idx == nums.len() {
                return if g1 != 0 && g1 == g2 { 1 } else { 0 };
            }

            if memo[idx][g1 as usize][g2 as usize] != -1 {
                return memo[idx][g1 as usize][g2 as usize];
            }

            let mut ans = 0;

            // Ignore
            ans = solve(idx + 1, g1, g2, nums, memo);

            // Put in seq1
            let ng1 = if g1 == 0 { nums[idx] } else { gcd(g1, nums[idx]) };
            ans = (ans + solve(idx + 1, ng1, g2, nums, memo)) % MOD;

            // Put in seq2
            let ng2 = if g2 == 0 { nums[idx] } else { gcd(g2, nums[idx]) };
            ans = (ans + solve(idx + 1, g1, ng2, nums, memo)) % MOD;

            memo[idx][g1 as usize][g2 as usize] = ans;
            ans
        }

        solve(0, 0, 0, &nums, &mut memo) as i32
    }
}