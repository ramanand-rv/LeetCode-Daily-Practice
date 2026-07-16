use std::cmp;

impl Solution {
    pub fn gcd_sum(nums: Vec<i32>) -> i64 {
        let n = nums.len();
        let mut a = Vec::with_capacity(n);
        let mut mx = 0;

        for &x in &nums {
            mx = cmp::max(mx, x);
            a.push(gcd(x, mx));
        }

        a.sort_unstable();

        let mut ans: i64 = 0;
        let mut l = 0;
        let mut r = n - 1;
        
        while l < r {
            ans += gcd(a[l], a[r]) as i64;
            l += 1;
            r -= 1;
        }

        ans
    }
}

// GCD (Euclidean algorithm)
fn gcd(mut a: i32, mut b: i32) -> i32 {
    while b != 0 {
        let t = a % b;
        a = b;
        b = t;
    }
    a
}