impl Solution {
    pub fn first_stable_index(nums: Vec<i32>, k: i32) -> i32 {
        let n = nums.len();
        let mut suf = vec![0; n];
        suf[n - 1] = nums[n - 1];

        // Suffix minimum
        for i in (0..n - 1).rev() {
            suf[i] = suf[i + 1].min(nums[i]);
        }

        let mut max_so_far = i32::MIN;
        for i in 0..n {
            max_so_far = max_so_far.max(nums[i]);
            if max_so_far - suf[i] <= k {
                return i as i32;
            }
        }
        -1
    }
}