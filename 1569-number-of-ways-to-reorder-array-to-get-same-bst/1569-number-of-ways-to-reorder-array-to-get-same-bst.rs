impl Solution {
    pub fn num_of_ways(nums: Vec<i32>) -> i32 {
        const MOD: i64 = 1_000_000_007;
        let n = nums.len();
        let mut born = vec![-1i64; n + 2];
        for (i, &x) in nums.iter().enumerate() {
            born[x as usize] = i as i64;
        }

        let mut fact: i64 = 1;
        for k in 2..=n as i64 {
            fact = fact * k % MOD;
        }

        let mut sizes: i64 = 1;
        let mut stack: Vec<usize> = vec![0];

        for v in 1..=n + 1 {
            while born[*stack.last().unwrap()] > born[v] {
                stack.pop();
                let below = *stack.last().unwrap();
                let size = (v - below - 1) as i64;
                sizes = (sizes as i128 * size as i128 % MOD as i128) as i64;
            }
            stack.push(v);
        }

        fn power(mut b: i64, mut e: i64, m: i64) -> i64 {
            let mut r = 1i64;
            b %= m;
            while e > 0 {
                if e & 1 == 1 {
                    r = (r as i128 * b as i128 % m as i128) as i64;
                }
                b = (b as i128 * b as i128 % m as i128) as i64;
                e >>= 1;
            }
            r
        }

        let inv = power(sizes, MOD - 2, MOD);
        let ans = ((fact as i128 * inv as i128 % MOD as i128) - 1 + MOD as i128) % MOD as i128;
        ans as i32
    }
}