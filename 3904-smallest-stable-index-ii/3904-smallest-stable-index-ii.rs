impl Solution {
    pub fn first_stable_index(nums: Vec<i32>, k: i32) -> i32 {
        let mut max_so_far = i32::MIN;
        let mut cand = 0;
        let mut c_max = 0;
        let n = nums.len();

        for i in 0..n {
            max_so_far = max_so_far.max(nums[i]);

            if i == cand {
                c_max = max_so_far;
            }

            if nums[i] < c_max - k {
                cand = i + 1;
            }
        }

        if cand < n { cand as i32 } else { -1 }
    }
}