impl Solution {
    pub fn smallest_index(nums: Vec<i32>) -> i32 {
        for (i, &x) in nums.iter().enumerate() {
            let mut n = x;
            let mut sum = 0;
            while n > 0 {
                sum += n % 10;
                n /= 10;
            }
            if sum == i as i32 {
                return i as i32;
            }
        }
        -1
    }
}