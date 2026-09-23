impl Solution {
    pub fn min_operations(nums: Vec<i32>, x: i32) -> i32 {
        let n = nums.len();
        let total: i32 = nums.iter().sum();
        let target = total - x;

        if target < 0 {
            return -1;
        }
        if target == 0 {
            return n as i32;
        }

        let mut left = 0;
        let mut sum = 0;
        let mut longest = -1;

        for right in 0..n {
            sum += nums[right];
            while left <= right && sum > target {
                sum -= nums[left];
                left += 1;
            }
            if sum == target {
                longest = longest.max((right - left + 1) as i32);
            }
        }

        if longest == -1 {
            -1
        } else {
            n as i32 - longest
        }
    }
}