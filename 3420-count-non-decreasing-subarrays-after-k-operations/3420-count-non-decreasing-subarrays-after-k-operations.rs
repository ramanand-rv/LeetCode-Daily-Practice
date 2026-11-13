use std::collections::VecDeque;

impl Solution {
    pub fn count_non_decreasing_subarrays(nums: Vec<i32>, k: i32) -> i64 {
        let n = nums.len();
        let mut starts = VecDeque::new(); // stores plateau start indices
        let mut r = (n as i32) - 1;
        let mut ans: i64 = 0;
        let mut water: i64 = 0;
        let k = k as i64;

        // Process each left endpoint from right to left
        for l in (0..n as i32).rev() {
            let x = nums[l as usize];
            
            // Flood plateaus to the right that are <= x
            while let Some(&front) = starts.front() {
                if nums[front] <= x {
                    let s = starts.pop_front().unwrap();
                    // End of this plateau: next plateau start, or r+1 if last
                    let end = if let Some(&front) = starts.front() {
                        front as i32
                    } else {
                        r + 1
                    };
                    water += (x - nums[s]) as i64 * (end - s as i32) as i64;
                } else {
                    break;
                }
            }
            
            // New plateau starts at l
            starts.push_front(l as usize);

            // Shrink window from right while water > k
            while water > k {
                let last_plateau = *starts.back().unwrap();
                // The bar at r belongs to the last plateau
                water -= nums[last_plateau] as i64 - nums[r as usize] as i64;
                // If the last plateau is only index r, remove it
                if last_plateau as i32 == r {
                    starts.pop_back();
                }
                r -= 1;
            }
            
            // All subarrays ending at <= r starting at l are good
            ans += (r - l + 1) as i64;
        }
        ans
    }
}