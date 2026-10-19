impl Solution {
    pub fn target_indices(nums: Vec<i32>, target: i32) -> Vec<i32> {
        let left = nums.iter().filter(|&&x| x < target).count() as i32;
        let right = nums.iter().filter(|&&x| x <= target).count() as i32;
        (left..right).collect()
    }
}