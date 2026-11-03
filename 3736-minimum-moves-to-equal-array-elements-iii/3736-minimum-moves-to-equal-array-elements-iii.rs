impl Solution {
    pub fn min_moves(nums: Vec<i32>) -> i32 {
        // Target must be the maximum element since we can only increment
        let max_val = *nums.iter().max().unwrap();
        let sum_val: i32 = nums.iter().sum();
        
        // Total moves = n * target - current sum
        (nums.len() as i32) * max_val - sum_val
    }
}