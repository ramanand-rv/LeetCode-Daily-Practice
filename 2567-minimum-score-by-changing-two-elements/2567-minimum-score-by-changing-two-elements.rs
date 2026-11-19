impl Solution {
    pub fn minimize_sum(nums: Vec<i32>) -> i32 {
        let mut s0 = i32::MAX;
        let mut s1 = i32::MAX;
        let mut s2 = i32::MAX;
        let mut l0 = i32::MIN;
        let mut l1 = i32::MIN;
        let mut l2 = i32::MIN;

        for &x in &nums {
            // Update 3 smallest
            if x < s0 {
                s2 = s1;
                s1 = s0;
                s0 = x;
            } else if x < s1 {
                s2 = s1;
                s1 = x;
            } else if x < s2 {
                s2 = x;
            }

            // Update 3 largest
            if x > l0 {
                l2 = l1;
                l1 = l0;
                l0 = x;
            } else if x > l1 {
                l2 = l1;
                l1 = x;
            } else if x > l2 {
                l2 = x;
            }
        }

        // Three ways to remove two elements:
        // 1. Remove two largest -> range = l2 - s0
        // 2. Remove two smallest -> range = l0 - s2
        // 3. Remove one smallest and one largest -> range = l1 - s1
        (l0 - s2).min(l2 - s0).min(l1 - s1)
    }
}