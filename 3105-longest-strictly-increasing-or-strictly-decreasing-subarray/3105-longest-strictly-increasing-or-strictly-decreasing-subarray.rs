impl Solution {
    pub fn longest_monotonic_subarray(nums: Vec<i32>) -> i32 {
        let mut best = 1;
        let mut up = 1;
        let mut down = 1;

        for i in 1..nums.len() {
            // Extend increasing streak if current > previous, else reset to 1
            if nums[i - 1] < nums[i] {
                up += 1;
            } else {
                up = 1;
            }

            // Extend decreasing streak if current < previous, else reset to 1
            if nums[i - 1] > nums[i] {
                down += 1;
            } else {
                down = 1;
            }

            // Update the global maximum streak length
            best = best.max(up).max(down);
        }

        best
    }
}