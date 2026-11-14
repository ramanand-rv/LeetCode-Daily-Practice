impl Solution {
    pub fn minimum_sum_subarray(nums: Vec<i32>, l: i32, r: i32) -> i32 {
        let n = nums.len();
        let mut ans = i32::MAX;

        // Try every possible starting index
        for i in 0..n {
            let mut sum = 0;
            
            // Extend the subarray to the right
            for j in i..n {
                sum += nums[j];
                let len = (j - i + 1) as i32;
                
                // Check if length is within bounds and sum is positive
                if len >= l && len <= r && sum > 0 {
                    ans = ans.min(sum);
                }
            }
        }

        // Return -1 if no valid subarray was found
        if ans == i32::MAX { -1 } else { ans }
    }
}