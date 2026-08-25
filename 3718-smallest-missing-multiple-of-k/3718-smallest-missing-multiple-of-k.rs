use std::collections::HashSet;

impl Solution {
    pub fn missing_multiple(nums: Vec<i32>, k: i32) -> i32 {
        let mut seen = HashSet::new();
        for &x in &nums {
            if x % k == 0 {
                seen.insert(x / k);
            }
        }
        let mut i = 1;
        while seen.contains(&i) {
            i += 1;
        }
        i * k
    }
}