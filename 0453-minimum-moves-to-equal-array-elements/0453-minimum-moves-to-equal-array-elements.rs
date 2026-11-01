impl Solution {
    pub fn min_moves(nums: Vec<i32>) -> i32 {
        let lo = *nums.iter().min().unwrap();
        nums.iter().map(|&x| x - lo).sum()
    }
}