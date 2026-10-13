impl Solution {
    pub fn max_alternating_sum(nums: Vec<i32>) -> i64 {
        let n = nums.len();
        let mut a: Vec<i64> = nums.iter().map(|&x| (x as i64) * (x as i64)).collect();
        a.sort();

        let mut ans: i64 = 0;
        let k = n / 2;

        for i in 0..k {
            ans -= a[i];
        }
        for i in k..n {
            ans += a[i];
        }

        ans
    }
}