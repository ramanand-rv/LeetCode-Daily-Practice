impl Solution {
    pub fn max_length(nums: Vec<i32>) -> i32 {
        let mut best = 2;
        let mut left = 0;
        let mut product = 1;

        // Helper function to calculate GCD
        fn gcd(mut a: i32, mut b: i32) -> i32 {
            while b != 0 {
                let temp = b;
                b = a % b;
                a = temp;
            }
            a
        }

        for right in 0..nums.len() {
            let x = nums[right];
            
            // While the new number shares a factor with the current window's product
            while gcd(product, x) > 1 {
                // Shrink the window from the left
                product /= nums[left];
                left += 1;
            }
            
            // Add the new number to the product
            product *= x;
            // Update the maximum length found
            best = best.max((right - left + 1) as i32);
        }

        best
    }
}