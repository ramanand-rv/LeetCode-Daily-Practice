impl Solution {
    pub fn find_kth_smallest(coins: Vec<i32>, k: i32) -> i64 {
        let mut coins = coins;
        coins.sort_unstable();
        let mut reduced = Vec::new();
        for &x in &coins {
            if reduced.iter().all(|&y| x % y != 0) {
                reduced.push(x);
            }
        }
        let n = reduced.len();
        let mut lcm_mask = vec![1i64; 1usize << n];
        for mask in 1usize..(1usize << n) {
            let bit = mask.trailing_zeros() as usize;
            let rest = mask ^ (1usize << bit);
            let a = lcm_mask[rest];
            let b = reduced[bit] as i64;
            lcm_mask[mask] = a / gcd(a, b) * b;
        }

        fn gcd(mut a: i64, mut b: i64) -> i64 {
            while b != 0 {
                let t = a % b;
                a = b;
                b = t;
            }
            a
        }

        let count = |m: i64| -> i64 {
            let mut total = 0;
            for mask in 1usize..(1usize << n) {
                let cnt = m / lcm_mask[mask];
                if mask.count_ones() & 1 == 1 {
                    total += cnt;
                } else {
                    total -= cnt;
                }
            }
            total
        };

        let mut lo = 1i64;
        let mut hi = (k as i64) * (reduced[0] as i64);
        while lo < hi {
            let mid = (lo + hi) / 2;
            if count(mid) >= k as i64 {
                hi = mid;
            } else {
                lo = mid + 1;
            }
        }
        lo
    }
}