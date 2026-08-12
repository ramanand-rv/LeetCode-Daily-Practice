use std::collections::HashMap;

impl Solution {
    pub fn max_subarray_length(nums: Vec<i32>, k: i32) -> i32 {
        let mut freq = HashMap::new();
        let mut i = 0;
        let mut res = 0;
        for (j, &x) in nums.iter().enumerate() {
            *freq.entry(x).or_insert(0) += 1;
            while freq[&x] > k {
                *freq.entry(nums[i]).or_insert(0) -= 1;
                i += 1;
            }
            res = res.max(j - i + 1);
        }
        res as i32
    }
}