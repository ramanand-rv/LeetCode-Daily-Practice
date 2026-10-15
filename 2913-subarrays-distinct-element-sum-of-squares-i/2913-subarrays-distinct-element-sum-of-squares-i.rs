impl Solution {
    pub fn sum_counts(nums: Vec<i32>) -> i32 {
        let n = nums.len();
        let mut ans: i64 = 0;

        for l in 0..n {
            let mut seen = [false; 101];
            let mut cnt = 0;
            for r in l..n {
                let x = nums[r] as usize;
                if !seen[x] {
                    seen[x] = true;
                    cnt += 1;
                }
                ans += (cnt * cnt) as i64;
            }
        }

        ans as i32
    }
}