impl Solution {
    pub fn minimum_deletions(nums: Vec<i32>) -> i32 {
        let n = nums.len();

        // Find indices of min and max
        let min_index = nums.iter().enumerate().min_by_key(|&(_, &v)| v).unwrap().0;
        let max_index = nums.iter().enumerate().max_by_key(|&(_, &v)| v).unwrap().0;

        let left = min_index.min(max_index);
        let right = min_index.max(max_index);

        // 1. Remove both from the front
        let front = right + 1;

        // 2. Remove both from the back
        let back = n - left;

        // 3. Remove one from each side
        let front_back = (left + 1) + (n - right);

        front.min(back).min(front_back) as i32
    }
}